#include "PluginProcessor.h"
#include "PluginEditor.h"
VelveteAudioProcessor::VelveteAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input",juce::AudioChannelSet::stereo()).withOutput("Output",juce::AudioChannelSet::stereo())),
      apvts(*this,nullptr,"Parameters",createParameterLayout()) {}
VelveteAudioProcessor::~VelveteAudioProcessor() {}
juce::AudioProcessorValueTreeState::ParameterLayout VelveteAudioProcessor::createParameterLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("GAIN_GAIN_DB_PN3I","Gain Gain",juce::NormalisableRange<float>(-24f,24f,0.01f),0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_DELAY_MS_2KBI","Delay Time",juce::NormalisableRange<float>(1f,2000f,0.01f),250f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_FEEDBACK_2KBI","Delay Feedback",juce::NormalisableRange<float>(0f,95f,0.01f),40f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_MIX_2KBI","Delay Mix",juce::NormalisableRange<float>(0f,100f,0.01f),30f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_THRESHOLD_WNKK","Compressor Threshold",juce::NormalisableRange<float>(-60f,0f,0.01f),-18f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_RATIO_WNKK","Compressor Ratio",juce::NormalisableRange<float>(1f,20f,0.1f),4f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_ATTACK_WNKK","Compressor Attack",juce::NormalisableRange<float>(0.1f,200f,0.01f),10f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_RELEASE_WNKK","Compressor Release",juce::NormalisableRange<float>(10f,2000f,0.01f),150f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_MAKEUP_WNKK","Compressor Makeup",juce::NormalisableRange<float>(0f,24f,0.01f),0f));
    return layout;
}
void VelveteAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    juce::dsp::ProcessSpec spec;
    spec.sampleRate=(uint32_t)sampleRate; spec.maximumBlockSize=(uint32_t)samplesPerBlock; spec.numChannels=(uint32_t)getTotalNumOutputChannels();
    gain_PN3I.prepare(spec); gain_PN3I.setGainDecibels(0f);
    delay_2KBI.prepare(spec); delay_2KBI.setMaximumDelayInSamples((int)(spec.sampleRate*2.0)); delayMix_2KBI.prepare(spec); delayMix_2KBI.setWetMixProportion(0.3f);
    comp_WNKK.prepare(spec); comp_WNKK.setThreshold(-18f); comp_WNKK.setRatio(4f); comp_WNKK.setAttack(10f); comp_WNKK.setRelease(150f); compMakeup_WNKK.prepare(spec); compMakeup_WNKK.setGainDecibels(0f);
}
void VelveteAudioProcessor::releaseResources() {}
bool VelveteAudioProcessor::isBusesLayoutSupported(const BusesLayout& l) const {
    return l.getMainOutputChannelSet()==juce::AudioChannelSet::stereo()&&l.getMainInputChannelSet()==juce::AudioChannelSet::stereo();
}
void VelveteAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    gain_PN3I.process(context);
    { delayMix_2KBI.pushDrySamples(block); delay_2KBI.process(context); delayMix_2KBI.mixWetSamples(block); }
    comp_WNKK.process(context); compMakeup_WNKK.process(context);
}
void VelveteAudioProcessor::getStateInformation(juce::MemoryBlock& d) {
    auto s=apvts.copyState(); std::unique_ptr<juce::XmlElement> xml(s.createXml()); copyXmlToBinary(*xml,d);
}
void VelveteAudioProcessor::setStateInformation(const void* d,int sz) {
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(d,sz));
    if(xml&&xml->hasTagName(apvts.state.getType())) apvts.replaceState(juce::ValueTree::fromXml(*xml));
}
juce::AudioProcessorEditor* VelveteAudioProcessor::createEditor() { return new VelveteAudioProcessorEditor(*this); }
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new VelveteAudioProcessor(); }
