// Auto-generated. Do not edit!

// (in-package serial_command_client.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class send_commandRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.command = null;
      this.buffer = null;
    }
    else {
      if (initObj.hasOwnProperty('command')) {
        this.command = initObj.command
      }
      else {
        this.command = 0;
      }
      if (initObj.hasOwnProperty('buffer')) {
        this.buffer = initObj.buffer
      }
      else {
        this.buffer = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type send_commandRequest
    // Serialize message field [command]
    bufferOffset = _serializer.uint8(obj.command, buffer, bufferOffset);
    // Serialize message field [buffer]
    bufferOffset = _arraySerializer.uint8(obj.buffer, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type send_commandRequest
    let len;
    let data = new send_commandRequest(null);
    // Deserialize message field [command]
    data.command = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [buffer]
    data.buffer = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.buffer.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'serial_command_client/send_commandRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1bda2754dbac533aafcdd7519ee5dd2d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 command
    uint8[] buffer
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new send_commandRequest(null);
    if (msg.command !== undefined) {
      resolved.command = msg.command;
    }
    else {
      resolved.command = 0
    }

    if (msg.buffer !== undefined) {
      resolved.buffer = msg.buffer;
    }
    else {
      resolved.buffer = []
    }

    return resolved;
    }
};

class send_commandResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
      this.buffer = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
      if (initObj.hasOwnProperty('buffer')) {
        this.buffer = initObj.buffer
      }
      else {
        this.buffer = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type send_commandResponse
    // Serialize message field [status]
    bufferOffset = _serializer.uint8(obj.status, buffer, bufferOffset);
    // Serialize message field [buffer]
    bufferOffset = _arraySerializer.uint8(obj.buffer, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type send_commandResponse
    let len;
    let data = new send_commandResponse(null);
    // Deserialize message field [status]
    data.status = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [buffer]
    data.buffer = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.buffer.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'serial_command_client/send_commandResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5be87bb0facce063fba275504571455a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 FAILURE=0
    uint8 SUCCESS=1
    uint8 status
    uint8[] buffer
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new send_commandResponse(null);
    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    if (msg.buffer !== undefined) {
      resolved.buffer = msg.buffer;
    }
    else {
      resolved.buffer = []
    }

    return resolved;
    }
};

// Constants for message
send_commandResponse.Constants = {
  FAILURE: 0,
  SUCCESS: 1,
}

module.exports = {
  Request: send_commandRequest,
  Response: send_commandResponse,
  md5sum() { return '6be57eb71fc2c8bb590b1bea40258ebc'; },
  datatype() { return 'serial_command_client/send_command'; }
};
