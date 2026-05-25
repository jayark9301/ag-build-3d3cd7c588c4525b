#pragma once
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
class VelveteAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    VelveteAudioProcessorEditor(VelveteAudioProcessor&);
    ~VelveteAudioProcessorEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    VelveteAudioProcessor& processorRef;
    VelveteLookAndFeel lnf;
    juce::Slider knob_GAIN_GAIN_DB_PN3I;
    juce::Label lbl_GAIN_GAIN_DB_PN3I;
    juce::AudioProcessorValueTreeState::SliderAttachment att_GAIN_GAIN_DB_PN3I;
    juce::Slider knob_DELAY_DELAY_MS_2KBI;
    juce::Label lbl_DELAY_DELAY_MS_2KBI;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_DELAY_MS_2KBI;
    juce::Slider knob_DELAY_FEEDBACK_2KBI;
    juce::Label lbl_DELAY_FEEDBACK_2KBI;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_FEEDBACK_2KBI;
    juce::Slider knob_DELAY_MIX_2KBI;
    juce::Label lbl_DELAY_MIX_2KBI;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_MIX_2KBI;
    juce::Slider knob_COMPRESSOR_THRESHOLD_WNKK;
    juce::Label lbl_COMPRESSOR_THRESHOLD_WNKK;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_THRESHOLD_WNKK;
    juce::Slider knob_COMPRESSOR_RATIO_WNKK;
    juce::Label lbl_COMPRESSOR_RATIO_WNKK;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_RATIO_WNKK;
    juce::Slider knob_COMPRESSOR_ATTACK_WNKK;
    juce::Label lbl_COMPRESSOR_ATTACK_WNKK;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_ATTACK_WNKK;
    juce::Slider knob_COMPRESSOR_RELEASE_WNKK;
    juce::Label lbl_COMPRESSOR_RELEASE_WNKK;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_RELEASE_WNKK;
    juce::Slider knob_COMPRESSOR_MAKEUP_WNKK;
    juce::Label lbl_COMPRESSOR_MAKEUP_WNKK;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_MAKEUP_WNKK;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VelveteAudioProcessorEditor)
};
