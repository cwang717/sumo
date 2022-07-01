/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2022 German Aerospace Center (DLR) and others.
// activitygen module
// Copyright 2010 TUM (Technische Universitaet Muenchen, http://www.tum.de/)
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    AGHouseholdWriter.cpp
/// @author  Chaojie Wang
/// @date    April 2022
///
// Class for writing Household objects in a SUMO-route file.
/****************************************************************************/
#include <config.h>

#include <utils/common/RGBColor.h>
#include <utils/iodevices/OutputDevice.h>
#include "city/AGHousehold.h"
#include "AGHouseholdWriter.h"


// ===========================================================================
// method definitions
// ===========================================================================

void
AGHouseholdWriter::addHousehold(AGHousehold& hh) {

    myHouseholdOutput.openTag("household")
    .writeAttr("x", hh.getPosition().getX())
    .writeAttr("y", hh.getPosition().getY())
    .writeAttr("adults", hh.getAdultNbr())
    .writeAttr("population", hh.getPeopleNbr());
    for (auto it = hh.getAdults().begin(); it != hh.getAdults().end(); ++it) {
        if (!it->isWorking()) continue;
        myHouseholdOutput.openTag("adult")
        .writeAttr("work_x", it->getWorkPosition().getPosition().getX())
        .writeAttr("work_y", it->getWorkPosition().getPosition().getY())
        .closeTag();
    }
    myHouseholdOutput.closeTag();
}


/****************************************************************************/
