#include "PluginEditor.h"
VelveteAudioProcessorEditor::VelveteAudioProcessorEditor(VelveteAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p),
      att_GAIN_GAIN_DB_PN3I(processorRef.apvts,"GAIN_GAIN_DB_PN3I",knob_GAIN_GAIN_DB_PN3I),
      att_DELAY_DELAY_MS_2KBI(processorRef.apvts,"DELAY_DELAY_MS_2KBI",knob_DELAY_DELAY_MS_2KBI),
      att_DELAY_FEEDBACK_2KBI(processorRef.apvts,"DELAY_FEEDBACK_2KBI",knob_DELAY_FEEDBACK_2KBI),
      att_DELAY_MIX_2KBI(processorRef.apvts,"DELAY_MIX_2KBI",knob_DELAY_MIX_2KBI),
      att_COMPRESSOR_THRESHOLD_WNKK(processorRef.apvts,"COMPRESSOR_THRESHOLD_WNKK",knob_COMPRESSOR_THRESHOLD_WNKK),
      att_COMPRESSOR_RATIO_WNKK(processorRef.apvts,"COMPRESSOR_RATIO_WNKK",knob_COMPRESSOR_RATIO_WNKK),
      att_COMPRESSOR_ATTACK_WNKK(processorRef.apvts,"COMPRESSOR_ATTACK_WNKK",knob_COMPRESSOR_ATTACK_WNKK),
      att_COMPRESSOR_RELEASE_WNKK(processorRef.apvts,"COMPRESSOR_RELEASE_WNKK",knob_COMPRESSOR_RELEASE_WNKK),
      att_COMPRESSOR_MAKEUP_WNKK(processorRef.apvts,"COMPRESSOR_MAKEUP_WNKK",knob_COMPRESSOR_MAKEUP_WNKK)
{
    setLookAndFeel(&lnf); setSize(480,370);
    knob_GAIN_GAIN_DB_PN3I.setSliderStyle(juce::Slider::Rotary); knob_GAIN_GAIN_DB_PN3I.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_GAIN_GAIN_DB_PN3I.setLookAndFeel(&lnf); addAndMakeVisible(knob_GAIN_GAIN_DB_PN3I); lbl_GAIN_GAIN_DB_PN3I.setText("Gain Gain",juce::dontSendNotification); lbl_GAIN_GAIN_DB_PN3I.setJustificationType(juce::Justification::centred); lbl_GAIN_GAIN_DB_PN3I.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_GAIN_GAIN_DB_PN3I);
    knob_DELAY_DELAY_MS_2KBI.setSliderStyle(juce::Slider::Rotary); knob_DELAY_DELAY_MS_2KBI.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DELAY_DELAY_MS_2KBI.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_DELAY_MS_2KBI); lbl_DELAY_DELAY_MS_2KBI.setText("Delay Time",juce::dontSendNotification); lbl_DELAY_DELAY_MS_2KBI.setJustificationType(juce::Justification::centred); lbl_DELAY_DELAY_MS_2KBI.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_DELAY_MS_2KBI);
    knob_DELAY_FEEDBACK_2KBI.setSliderStyle(juce::Slider::Rotary); knob_DELAY_FEEDBACK_2KBI.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DELAY_FEEDBACK_2KBI.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_FEEDBACK_2KBI); lbl_DELAY_FEEDBACK_2KBI.setText("Delay Feedback",juce::dontSendNotification); lbl_DELAY_FEEDBACK_2KBI.setJustificationType(juce::Justification::centred); lbl_DELAY_FEEDBACK_2KBI.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_FEEDBACK_2KBI);
    knob_DELAY_MIX_2KBI.setSliderStyle(juce::Slider::Rotary); knob_DELAY_MIX_2KBI.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DELAY_MIX_2KBI.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_MIX_2KBI); lbl_DELAY_MIX_2KBI.setText("Delay Mix",juce::dontSendNotification); lbl_DELAY_MIX_2KBI.setJustificationType(juce::Justification::centred); lbl_DELAY_MIX_2KBI.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_MIX_2KBI);
    knob_COMPRESSOR_THRESHOLD_WNKK.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_THRESHOLD_WNKK.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_COMPRESSOR_THRESHOLD_WNKK.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_THRESHOLD_WNKK); lbl_COMPRESSOR_THRESHOLD_WNKK.setText("Compressor Threshold",juce::dontSendNotification); lbl_COMPRESSOR_THRESHOLD_WNKK.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_THRESHOLD_WNKK.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_THRESHOLD_WNKK);
    knob_COMPRESSOR_RATIO_WNKK.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_RATIO_WNKK.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_COMPRESSOR_RATIO_WNKK.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_RATIO_WNKK); lbl_COMPRESSOR_RATIO_WNKK.setText("Compressor Ratio",juce::dontSendNotification); lbl_COMPRESSOR_RATIO_WNKK.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_RATIO_WNKK.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_RATIO_WNKK);
    knob_COMPRESSOR_ATTACK_WNKK.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_ATTACK_WNKK.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_COMPRESSOR_ATTACK_WNKK.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_ATTACK_WNKK); lbl_COMPRESSOR_ATTACK_WNKK.setText("Compressor Attack",juce::dontSendNotification); lbl_COMPRESSOR_ATTACK_WNKK.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_ATTACK_WNKK.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_ATTACK_WNKK);
    knob_COMPRESSOR_RELEASE_WNKK.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_RELEASE_WNKK.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_COMPRESSOR_RELEASE_WNKK.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_RELEASE_WNKK); lbl_COMPRESSOR_RELEASE_WNKK.setText("Compressor Release",juce::dontSendNotification); lbl_COMPRESSOR_RELEASE_WNKK.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_RELEASE_WNKK.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_RELEASE_WNKK);
    knob_COMPRESSOR_MAKEUP_WNKK.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_MAKEUP_WNKK.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_COMPRESSOR_MAKEUP_WNKK.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_MAKEUP_WNKK); lbl_COMPRESSOR_MAKEUP_WNKK.setText("Compressor Makeup",juce::dontSendNotification); lbl_COMPRESSOR_MAKEUP_WNKK.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_MAKEUP_WNKK.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_MAKEUP_WNKK);
}
VelveteAudioProcessorEditor::~VelveteAudioProcessorEditor() { setLookAndFeel(nullptr); }
void VelveteAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colour(0xff0d1117));
    g.setColour(juce::Colour(0xff4d8bff).withAlpha(0.1f)); g.fillRect(0,0,getWidth(),50);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.45f)); g.setFont(juce::Font("Inter",10.f,juce::Font::bold));
    g.drawText("ARCHERGATE",16,6,getWidth()-32,14,juce::Justification::left);
    g.setColour(juce::Colour(0xff4d8bff)); g.setFont(juce::Font("Inter",15.f,juce::Font::bold));
    g.drawText("VELVETE",16,20,getWidth()-32,18,juce::Justification::centred);
}
void VelveteAudioProcessorEditor::resized() {
    knob_GAIN_GAIN_DB_PN3I.setBounds(20+0*110,60+0*90,85,70); lbl_GAIN_GAIN_DB_PN3I.setBounds(20+0*110,127+0*90,85,13);
    knob_DELAY_DELAY_MS_2KBI.setBounds(20+1*110,60+0*90,85,70); lbl_DELAY_DELAY_MS_2KBI.setBounds(20+1*110,127+0*90,85,13);
    knob_DELAY_FEEDBACK_2KBI.setBounds(20+2*110,60+0*90,85,70); lbl_DELAY_FEEDBACK_2KBI.setBounds(20+2*110,127+0*90,85,13);
    knob_DELAY_MIX_2KBI.setBounds(20+3*110,60+0*90,85,70); lbl_DELAY_MIX_2KBI.setBounds(20+3*110,127+0*90,85,13);
    knob_COMPRESSOR_THRESHOLD_WNKK.setBounds(20+0*110,60+1*90,85,70); lbl_COMPRESSOR_THRESHOLD_WNKK.setBounds(20+0*110,127+1*90,85,13);
    knob_COMPRESSOR_RATIO_WNKK.setBounds(20+1*110,60+1*90,85,70); lbl_COMPRESSOR_RATIO_WNKK.setBounds(20+1*110,127+1*90,85,13);
    knob_COMPRESSOR_ATTACK_WNKK.setBounds(20+2*110,60+1*90,85,70); lbl_COMPRESSOR_ATTACK_WNKK.setBounds(20+2*110,127+1*90,85,13);
    knob_COMPRESSOR_RELEASE_WNKK.setBounds(20+3*110,60+1*90,85,70); lbl_COMPRESSOR_RELEASE_WNKK.setBounds(20+3*110,127+1*90,85,13);
    knob_COMPRESSOR_MAKEUP_WNKK.setBounds(20+0*110,60+2*90,85,70); lbl_COMPRESSOR_MAKEUP_WNKK.setBounds(20+0*110,127+2*90,85,13);
}
