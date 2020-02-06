/*
  ==============================================================================

    ACInterfaceDefines.h
    Created: 3 Jan 2020 11:35:05pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

#pragma once

#define MAIN_PANEL_WIDTH    450 //450
#define MAIN_PANEL_HEIGHT   200 //200

#define TOP_PANEL_WIDTH     MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT    MAIN_PANEL_HEIGHT/7

#define FILTER_GRAPH_WIDTH  MAIN_PANEL_WIDTH
#define FILTER_GRAPH_HEIGHT TOP_PANEL_HEIGHT*4

#define EQDial_PANEL_WIDTH      MAIN_PANEL_WIDTH
#define EQDial_PANEL_HEIGHT     TOP_PANEL_HEIGHT*2

const Colour ACColour_1 = Colour(105, 105, 105);
const Colour ACColour_2 = Colour(0, 0, 0).withAlpha(0.0f);
const Colour ACColour_3 = Colour(0, 0, 0).withAlpha(0.3f);
const Colour ACColour_4 = Colour(0, 0, 0).withAlpha(0.6f);
const Colour ACColour_5 = Colour(105, 105, 105).withAlpha(0.3f);
const Colour ACColour_6 = Colour(0, 0, 0).withAlpha(0.8f);
const Colour ACColour_7 = Colour(125, 125, 125);

const Font font_1 ( "Helvetica Neue", 12.00f, Font::bold);
const Font font_2 ( "Helvetica Neue", 22.00f, Font::bold);
const Font font_3 ( "Helvetica Neue", 48.00f, Font::bold);
