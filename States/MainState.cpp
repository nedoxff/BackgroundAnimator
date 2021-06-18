//
// Created by nedo on 8.06.21.
//

/**
 * Includes.
 */
#include "MainState.hpp"
#include "../Window/App.hpp"

//Original size of the buttonsPanel is pretty small, so their size is multiplied by this value.
#define SIZE_MULTIPLIER 1.5
//Offset between each button displayed in the ScrollablePanel.
#define BUTTON_OFFSET 10


void MainState::OnCall(App *app) {
    //Load UI
    this->app = app;
    this->settings = GlobalSettings::Get();
    this->resources = ResourceContainer::Get();
    LoadUI();
    //Load Music
    Logger::Info("Loading music from " + settings->MusicPath + "..", true);
    if(!settings->Music.openFromFile(settings->MusicPath.toStdString()))
        Logger::EndStatus(false, true, "MainState: Failed to load music!");
    else
        Logger::EndStatus(true);

    //Get TGUI widgets
    controls = GetUI(tgui::ChildWindow, "Controls");

    play = controls->get<tgui::Button>("Play");
    play->getRenderer()->setFont(resources->GetFont("emoji"));

    progress = controls->get<tgui::ProgressBar>("Progress");
    progressSlider = controls->get<tgui::Slider>("ProgressSlider");
    buttonsPanel = controls->get<tgui::ScrollablePanel>("Buttons");
    tabs = controls->get<tgui::Tabs>("Tabs");
    durationString = tgui::String::fromNumber(settings->Music.getDuration().asSeconds());

    //Get settings
    buttonSettings = MainButtonsSettings::Get();

    //Push categories from settings to Tabs.
    LoadCategories();
    //Push buttonsPanel from the first category.
    LoadButtons(buttonSettings.GetButtons().begin()->first);

    //Show the UI.
    ShowUI();
}

void MainState::OnAttachEvents() {
    auto length = settings->Music.getDuration().asMilliseconds();
    progress->setMaximum(length);
    progress->setText("0.0/" + durationString);

    progressSlider->setMaximum(static_cast<float>(length));
    progressSlider->onValueChange.connect([=]{
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            auto value = static_cast<int>(progressSlider->getValue());
            progress->setValue(value);
            progress->setText(tgui::String::fromNumberRounded(static_cast<float>(value) / 1000.f, 2) + "/" + durationString);
            settings->Music.setPlayingOffset(sf::milliseconds(value));
        }
    });

    //When the tab is changed, the panel should clear
    //and new buttonsPanel should be added.
    tabs->onTabSelect.connect([=]{
        LoadButtons(tabs->getSelected());
    });

    play->onClick.connect([=]{
        Play();
    });
}

tgui::String MainState::GetName() {
    return "MainState";
}

void MainState::ShowUI() {
    controls->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}

void MainState::HideUI() {
    State::HideUI();
}

void MainState::LoadCategories() {
    Logger::Info("MainState: Loading categories..");

    //Get buttonsPanel from settings.
    auto buttons = buttonSettings.GetButtons();
    //Get each key from the map.
    for(auto& category: buttons)
        tabs->add(category.first);

    Logger::Success("MainState: Successfully loaded categories!");
}

void MainState::LoadButtons(const tgui::String& category) {
    Logger::Info("MainState: Loading buttons from \"" + category + "\"..");

    //Get buttonsPanel from the map.
    auto buttons = buttonSettings.GetButtons().at(category);
    //Change the tab to that category.
    tabs->select(category);
    //Clear all buttonsPanel.
    buttonsPanel->removeAllWidgets();
    //The counter will increase each time a button is added,
    //and is used when defining the position of the button.
    int counter = 0;

    for(auto& obj: buttons)
    {
        //Create a new TGUI button.
        auto button = tgui::Button::create(obj.first);
        button->onClick.connect([=]{
            if(settings->Music.getStatus() == sf::SoundSource::Playing)
                Play();
            obj.second(app);
        });
        //Multiply the size of the button by SIZE_MULTIPLIER.
        auto size = button->getSize();
        button->setSize({size.x * SIZE_MULTIPLIER, size.y * SIZE_MULTIPLIER});
        //Center the button by X, and move the button by Y by `counter * (size + BUTTON_OFFSET)`
        button->setPosition({"(parent.innersize - size) / 2", static_cast<float>(counter) * (size.y * SIZE_MULTIPLIER + BUTTON_OFFSET)});

        //Add the button!
        buttonsPanel->add(button);
        counter++;
    }

    Logger::Success("MainState: Successfully loaded buttons!");
}

void MainState::Tick() {
    if(settings->Music.getStatus() == sf::SoundSource::Playing) {
        auto offset = settings->Music.getPlayingOffset().asMilliseconds();
        progress->setValue(offset);
        progress->setText(tgui::String::fromNumberRounded(static_cast<float>(offset) / 1000.f, 2) + "/" + durationString);
        progressSlider->setValue(static_cast<float>(offset));
    }
}

void MainState::Play() {
    auto status = settings->Music.getStatus();
    if(status == sf::SoundSource::Paused || status == sf::SoundSource::Stopped) {
        play->setText("⏸");
        settings->Music.play();
    }
    else {
        play->setText("▶");
        settings->Music.pause();
    }
}
