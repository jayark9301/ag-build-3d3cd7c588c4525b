#pragma once
#include <JuceHeader.h>
class VelveteAudioProcessor : public juce::AudioProcessor {
public:
    VelveteAudioProcessor();
    ~VelveteAudioProcessor() override;
    void prepareToPlay(double, int) override;
    void releaseResources() override;
    bool isBusesLayoutSupported(const BusesLayout&) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return "Velvete"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 2.0; }
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;
    juce::AudioProcessorValueTreeState apvts;
private:
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::dsp::Gain<float> gain_PN3I;
    juce::dsp::DelayLine<float,juce::dsp::DelayLineInterpolationTypes::Lagrange3rd> delay_2KBI { 96000 };
    juce::dsp::DryWetMixer<float> delayMix_2KBI;
    juce::dsp::Compressor<float> comp_WNKK;
    juce::dsp::Gain<float> compMakeup_WNKK;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VelveteAudioProcessor)
};
