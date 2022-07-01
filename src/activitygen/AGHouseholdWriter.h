/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2010-2022 German Aerospace Center (DLR) and others.
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
/// @file    AGHouseholdWriter.h
/// @author  Chaojie Wang
/// @date    April 2022
///
// Class for writing Household objects in a SUMO-route file.
/****************************************************************************/
#pragma once
#include <config.h>

// ===========================================================================
// class declarations
// ===========================================================================
class OutputDevice;
class AGHousehold;


// ===========================================================================
// class definitions
// ===========================================================================
class AGHouseholdWriter {
public:
    AGHouseholdWriter(OutputDevice& file) : myHouseholdOutput(file) {};

    void addHousehold(AGHousehold& trip);

private:
    OutputDevice& myHouseholdOutput;

private:
    /// @brief Invalidated copy constructor.
    AGHouseholdWriter(const AGHouseholdWriter&);

    /// @brief Invalidated assignment operator.
    AGHouseholdWriter& operator=(const AGHouseholdWriter&);

};
