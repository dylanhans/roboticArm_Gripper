/* ELEC 498/490 CODE TEMPLATE */
// ROS Code Draft

// Move position to end point
// Consists of file directory and file with simulated environment. 
// References joints included in movement with motion changes
rostopic pub /arm_controller/command trajectory_msgs/JointTrajectory 
'{joint_names: ["arm_base_joint","shoulder_joint", "bottom_wrist_joint", "elbow_joint","top_wrist_joint"], 
points: [{positions: [-0.1, 0.5, 0.02, 0, 0], time_from_start: [1,0]}]}' -1

// Insert above statement back to regular stable position
    
// Assign these to certain functions when pressed or initiated 
    // Ex. Grabbing, Reset, Large object, Normal, etc
    ...

// ----------------------------------------------------------------------- //
