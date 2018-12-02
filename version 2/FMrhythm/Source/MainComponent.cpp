/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
	menuBar_.reset(new MenuBarComponent(this));
	addAndMakeVisible(menuBar_.get());
	setApplicationCommandManagerToWatch(&commandManager_);
	commandManager_.registerAllCommandsForTarget(this);
	addKeyListener(commandManager_.getKeyMappings());

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
	auto b = getLocalBounds();
	menuBar_->setBounds(b.removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
}

//==============================================================================
StringArray MainComponent::getMenuBarNames()
{
	return { "File", "Edit" };
}

PopupMenu MainComponent::getMenuForIndex(int menuIndex, const String& /*menuName*/)
{
	PopupMenu menu;
	
		if (menuIndex == 0)
		{
			menu.addCommandItem(&commandManager_, CommandIDs::fileOpen);
			menu.addCommandItem(&commandManager_, CommandIDs::fileSave);
			menu.addCommandItem(&commandManager_, CommandIDs::fileImport);
			menu.addCommandItem(&commandManager_, CommandIDs::fileExport);
		}
		//else if (menuIndex == 1)
		//{
		//	menu.addCommandItem(&commandManager, CommandIDs::outerColourRed);
		//	menu.addCommandItem(&commandManager, CommandIDs::outerColourGreen);
		//	menu.addCommandItem(&commandManager, CommandIDs::outerColourBlue);
		//}

	return menu;
}

void MainComponent::menuItemSelected(int /*menuItemID*/, int /*topLevelMenuIndex*/)
{
}

//==============================================================================
ApplicationCommandTarget* MainComponent::getNextCommandTarget()
{
	return NULL;
}

void MainComponent::getAllCommands(Array<CommandID>& c)
{
	Array<CommandID> commands{ CommandIDs::fileOpen,
		CommandIDs::fileSave,
		CommandIDs::fileImport,
		CommandIDs::fileExport };

	c.addArray(commands);
}

void MainComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	switch (commandID)
	{
	case CommandIDs::fileOpen:
		result.setInfo("Open...", "Open a FMRhythm project file", "Menu", 0);
		result.addDefaultKeypress('o', ModifierKeys::commandModifier);
		break;
	case CommandIDs::fileSave:
		result.setInfo("Save...", "Save FMRhythm project to file", "Menu", 0);
		result.addDefaultKeypress('s', ModifierKeys::commandModifier);
		break;
	case CommandIDs::fileImport:
		result.setInfo("Import MIDI", "Import a MIDI file", "Menu", 0);
		result.addDefaultKeypress('i', ModifierKeys::commandModifier);
		break;
	case CommandIDs::fileExport:
		result.setInfo("Export MIDI", "Export to a MIDI file", "Menu", 0);
		result.addDefaultKeypress('e', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool MainComponent::perform(const InvocationInfo& info)
{
	switch (info.commandID)
	{
	case CommandIDs::fileOpen:
		break;
	case CommandIDs::fileSave:
		break;
	case CommandIDs::fileImport:
		break;
	case CommandIDs::fileExport:
		break;
	default:
		return false;
	}

	return true;
}
