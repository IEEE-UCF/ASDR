; Auto-generated. Do not edit!


(cl:in-package stepper_motor-srv)


;//! \htmlinclude set_stepper_motor-request.msg.html

(cl:defclass <set_stepper_motor-request> (roslisp-msg-protocol:ros-message)
  ((velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0))
)

(cl:defclass set_stepper_motor-request (<set_stepper_motor-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_stepper_motor-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_stepper_motor-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name stepper_motor-srv:<set_stepper_motor-request> is deprecated: use stepper_motor-srv:set_stepper_motor-request instead.")))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <set_stepper_motor-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader stepper_motor-srv:velocity-val is deprecated.  Use stepper_motor-srv:velocity instead.")
  (velocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_stepper_motor-request>) ostream)
  "Serializes a message object of type '<set_stepper_motor-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_stepper_motor-request>) istream)
  "Deserializes a message object of type '<set_stepper_motor-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_stepper_motor-request>)))
  "Returns string type for a service object of type '<set_stepper_motor-request>"
  "stepper_motor/set_stepper_motorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_stepper_motor-request)))
  "Returns string type for a service object of type 'set_stepper_motor-request"
  "stepper_motor/set_stepper_motorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_stepper_motor-request>)))
  "Returns md5sum for a message object of type '<set_stepper_motor-request>"
  "e4ff88b32504f688719a85e0753f63ce")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_stepper_motor-request)))
  "Returns md5sum for a message object of type 'set_stepper_motor-request"
  "e4ff88b32504f688719a85e0753f63ce")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_stepper_motor-request>)))
  "Returns full string definition for message of type '<set_stepper_motor-request>"
  (cl:format cl:nil "float32 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_stepper_motor-request)))
  "Returns full string definition for message of type 'set_stepper_motor-request"
  (cl:format cl:nil "float32 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_stepper_motor-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_stepper_motor-request>))
  "Converts a ROS message object to a list"
  (cl:list 'set_stepper_motor-request
    (cl:cons ':velocity (velocity msg))
))
;//! \htmlinclude set_stepper_motor-response.msg.html

(cl:defclass <set_stepper_motor-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass set_stepper_motor-response (<set_stepper_motor-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_stepper_motor-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_stepper_motor-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name stepper_motor-srv:<set_stepper_motor-response> is deprecated: use stepper_motor-srv:set_stepper_motor-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_stepper_motor-response>) ostream)
  "Serializes a message object of type '<set_stepper_motor-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_stepper_motor-response>) istream)
  "Deserializes a message object of type '<set_stepper_motor-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_stepper_motor-response>)))
  "Returns string type for a service object of type '<set_stepper_motor-response>"
  "stepper_motor/set_stepper_motorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_stepper_motor-response)))
  "Returns string type for a service object of type 'set_stepper_motor-response"
  "stepper_motor/set_stepper_motorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_stepper_motor-response>)))
  "Returns md5sum for a message object of type '<set_stepper_motor-response>"
  "e4ff88b32504f688719a85e0753f63ce")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_stepper_motor-response)))
  "Returns md5sum for a message object of type 'set_stepper_motor-response"
  "e4ff88b32504f688719a85e0753f63ce")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_stepper_motor-response>)))
  "Returns full string definition for message of type '<set_stepper_motor-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_stepper_motor-response)))
  "Returns full string definition for message of type 'set_stepper_motor-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_stepper_motor-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_stepper_motor-response>))
  "Converts a ROS message object to a list"
  (cl:list 'set_stepper_motor-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'set_stepper_motor)))
  'set_stepper_motor-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'set_stepper_motor)))
  'set_stepper_motor-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_stepper_motor)))
  "Returns string type for a service object of type '<set_stepper_motor>"
  "stepper_motor/set_stepper_motor")