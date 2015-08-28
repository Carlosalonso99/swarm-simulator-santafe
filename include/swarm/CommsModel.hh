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

/// \file CommsModel.hh
/// \brief Manages how the communication behave between the members of the team.

#ifndef __SWARM_COMMS_MODEL_HH__
#define __SWARM_COMMS_MODEL_HH__

#include <map>
#include <string>
#include <utility>
#include <vector>
#include <gazebo/common/Time.hh>
#include <gazebo/physics/PhysicsTypes.hh>
#include <ignition/math.hh>
#include <sdf/sdf.hh>

#include "swarm/SwarmTypes.hh"

namespace swarm
{
  /// \brief Class used to store information about the communication model.
  class IGNITION_VISIBLE CommsModel
  {
    /// \brief Class constructor.
    ///
    /// \param[in] _swarm Pointer to the swarm.
    /// \param[in] _world Pointer to the Gazebo world.
    /// \param[in] _sdf Pointer to the SDF element of the plugin.
    public: CommsModel(SwarmMembershipPtr _swarm,
                       gazebo::physics::WorldPtr _world,
                       sdf::ElementPtr _sdf);

    /// \brief Class destructor.
    public: virtual ~CommsModel() = default;

    /// \brief Update the state of the communication model (outages, visibility
    /// between nodes and neighbors).
    public: void Update();

    /// \brief Decide if each member of the swarm enters into a comms outage.
    private: void UpdateOutages();

    /// \brief Update the neighbors list of each member of the swarm.
    private: void UpdateNeighbors();

    /// \brief Update the neighbor list for a single robot and notifies the
    /// robot with the updated list.
    ///
    /// \param[in] _address Address of the robot to be updated.
    private: void UpdateNeighborList(const std::string &_address);

    /// \brief Update the visibility state between vehicles.
    private: void UpdateVisibility();

    /// \brief Check if there is line of sight between two points in the world.
    ///
    /// \param[in] _p1 A 3D point.
    /// \param[in] _p2 Another 3D point.
    /// \param[out] _entities Vector of obstacles between the objects.
    /// If the points have line of sight, the vector has only one element and
    /// it's the empty string. If there's no line of sight this parameter
    /// contains the name of the first and last entities on the way from
    /// the starting point to the end point.
    /// ToDo: Improve this function if needed to return all the obstacles and
    /// not only the first and last.
    /// \return True if the points have line of sight or false otherwise.
    private: bool LineOfSight(const ignition::math::Pose3d &_p1,
                              const ignition::math::Pose3d &_p2,
                              std::vector<std::string> &_entities);

    /// \brief Check if a "comms_model" block exists in the SDF element of the
    /// plugin. If so, update the value of the default parameters with the one
    /// read from the world file.
    /// \param[in] _sdf Pointer to the SDF element of the plugin.
    private: void LoadParameters(sdf::ElementPtr _sdf);

    /// \brief Minimum free-space distance (m) between two nodes to be
    /// neighbors. Set to <0 for no limit.
    private: double neighborDistanceMin = -1.0;

    /// \brief Maximum free-space distance (m) between two nodes to be
    /// neighbors. Set to <0 for no limit.
    private: double neighborDistanceMax = -1.0;

    /// \brief Equivalent free space distance (m) that is "consumed" by an
    /// intervening non-solid obstacle (forest, etc.).
    /// Set to <0 for infinite penalty (i.e., one obstacle blocks neighbors).
    private: double neighborDistancePenaltyTree = 0.0;

    /// \brief Minimum free-space distance (m) between two nodes to communicate
    /// (must also be neighbors). Set to <0 for no limit.
    private: double commsDistanceMin = -1.0;

    /// \brief Maximum free-space distance (m) between two nodes to communicate
    /// (must also be neighbors). Set to <0 for no limit.
    private: double commsDistanceMax = -1.0;

    /// \brief Equivalent free space distance (m) that is "consumed" by an
    /// intervening non-solid obstacle (forest, etc.).
    /// Set to <0 for infinite penalty (i.e., one obstacle blocks comms).
    private: double commsDistancePenaltyTree = 0.0;

    /// \brief Minimum probability of dropping a given packet.
    /// Used with uniform drop probability model.
    private: double commsDropProbabilityMin = 0.0;

    /// \brief Maximum probability of dropping a given packet.
    /// Used with uniform drop probability model.
    private: double commsDropProbabilityMax = 0.0;

    /// \brief Probability of going into a comms outage at each second.
    private: double commsOutageProbability = 0.0;

    /// \brief Minimum length of comms outage (secs). Set to <0 for no limit.
    /// Used with uniform outage duration probability model.
    private: double commsOutageDurationMin = -1.0;

    /// \brief Maximum length of comms outage (secs). Set to <0 for no limit.
    /// Used with uniform outage duration probability model.
    private: double commsOutageDurationMax = -1.0;

    /// \brief Pointer to the swarm.
    private: SwarmMembershipPtr swarm;

    /// \brief Pointer to the Gazebo world.
    private: gazebo::physics::WorldPtr world;

    /// \brief Keep track of update sim-time.
    private: gazebo::common::Time lastUpdateTime;

    // \brief Ray used to test for line of sight between vehicles.
    private: gazebo::physics::RayShapePtr ray;

    /// \brief Visibility between vehicles. The key is a pair with the
    /// addresses of the vehicles involved. The value is a vector of strings
    /// that stores the entity names of the first and last obstacles between the
    /// vehicles. If there is line of sight the value contains a vector of one
    /// element (empty string).
    private: std::map<std::pair<std::string, std::string>,
               std::vector<std::string>> visibility;
  };
}  // namespace
#endif