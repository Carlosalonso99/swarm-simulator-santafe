/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <gtest/gtest.h>

#include "battery_plugin.hh"

using namespace swarm;

GZ_REGISTER_MODEL_PLUGIN(BatteryPlugin)

//////////////////////////////////////////////////
BatteryPlugin::BatteryPlugin()
: RobotPlugin()
{
}

//////////////////////////////////////////////////
void BatteryPlugin::Load(sdf::ElementPtr /*_sdf*/)
{
  EXPECT_NEAR(this->BatteryCapacity(), 3500, 1e-6);
  EXPECT_NEAR(this->BatteryConsumption(), 1500, 1e-6);
  EXPECT_NEAR(this->BatteryConsumptionFactor(), 0.7, 1e-6);

  this->world = gazebo::physics::get_world("default");
}

//////////////////////////////////////////////////
void BatteryPlugin::Update(const gazebo::common::UpdateInfo & /*_info*/)
{
  static int counter = 1;

  double expectedBattery = this->BatteryStartCapacity() -
    (this->BatteryConsumption() *
    this->BatteryConsumptionFactor() *
    ((this->world->GetPhysicsEngine()->GetMaxStepSize() * counter)/3600.0));

  EXPECT_NEAR(this->BatteryCapacity(), expectedBattery, 1e-4);

  ++counter;
}
