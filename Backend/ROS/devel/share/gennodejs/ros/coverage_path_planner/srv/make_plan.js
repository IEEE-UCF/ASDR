// Auto-generated. Do not edit!

// (in-package coverage_path_planner.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class make_planRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type make_planRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type make_planRequest
    let len;
    let data = new make_planRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'coverage_path_planner/make_planRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new make_planRequest(null);
    return resolved;
    }
};

class make_planResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.plan = null;
    }
    else {
      if (initObj.hasOwnProperty('plan')) {
        this.plan = initObj.plan
      }
      else {
        this.plan = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type make_planResponse
    // Serialize message field [plan]
    // Serialize the length for message field [plan]
    bufferOffset = _serializer.uint32(obj.plan.length, buffer, bufferOffset);
    obj.plan.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Pose.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type make_planResponse
    let len;
    let data = new make_planResponse(null);
    // Deserialize message field [plan]
    // Deserialize array length for message field [plan]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.plan = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.plan[i] = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 56 * object.plan.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'coverage_path_planner/make_planResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '89526be3bcb6a9380bfd5badd496049d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Pose[] plan
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new make_planResponse(null);
    if (msg.plan !== undefined) {
      resolved.plan = new Array(msg.plan.length);
      for (let i = 0; i < resolved.plan.length; ++i) {
        resolved.plan[i] = geometry_msgs.msg.Pose.Resolve(msg.plan[i]);
      }
    }
    else {
      resolved.plan = []
    }

    return resolved;
    }
};

module.exports = {
  Request: make_planRequest,
  Response: make_planResponse,
  md5sum() { return '89526be3bcb6a9380bfd5badd496049d'; },
  datatype() { return 'coverage_path_planner/make_plan'; }
};
