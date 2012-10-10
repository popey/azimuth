/*=============================================================================
| Copyright 2012 Matthew D. Steele <mdsteele@alum.mit.edu>                    |
|                                                                             |
| This file is part of Azimuth.                                               |
|                                                                             |
| Azimuth is free software: you can redistribute it and/or modify it under    |
| the terms of the GNU General Public License as published by the Free        |
| Software Foundation, either version 3 of the License, or (at your option)   |
| any later version.                                                          |
|                                                                             |
| Azimuth is distributed in the hope that it will be useful, but WITHOUT      |
| ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       |
| FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for   |
| more details.                                                               |
|                                                                             |
| You should have received a copy of the GNU General Public License along     |
| with Azimuth.  If not, see <http://www.gnu.org/licenses/>.                  |
=============================================================================*/

#pragma once
#ifndef AZIMUTH_STATE_SHIP_H_
#define AZIMUTH_STATE_SHIP_H_

#include <stdbool.h>

#include "azimuth/state/player.h"
#include "azimuth/state/uid.h"
#include "azimuth/util/vector.h"

/*===========================================================================*/

typedef struct {
  bool up, down, left, right;
  bool fire_pressed, fire_held;
  bool ordn, util, burn;
} az_controls_t;

typedef struct {
  az_controls_t controls;
  az_player_t player;
  az_vector_t position; // pixels
  az_vector_t velocity; // pixels/second
  double angle; // radians
  struct {
    bool active;
    az_uid_t node_uid;
    double distance;
  } tractor_beam;
} az_ship_t;

// Return true if the given point should count as intersecting the ship's
// shield perimeter.
bool az_point_hits_ship(const az_ship_t *ship, az_vector_t point);

/*===========================================================================*/

#endif // AZIMUTH_STATE_SHIP_H_
