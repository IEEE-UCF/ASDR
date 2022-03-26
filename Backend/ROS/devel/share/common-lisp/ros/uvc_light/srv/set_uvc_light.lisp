; Auto-generated. Do not edit!


(cl:in-package uvc_light-srv)


;//! \htmlinclude set_uvc_light-request.msg.html

(cl:defclass <set_uvc_light-request> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0))
)

(cl:defclass set_uvc_light-request (<set_uvc_light-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_uvc_light-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_uvc_light-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name uvc_light-srv:<set_uvc_light-request> is deprecated: use uvc_light-srv:set_uvc_light-request instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <set_uvc_light-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uvc_light-srv:state-val is deprecated.  Use uvc_light-srv:state instead.")
  (state m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<set_uvc_light-request>)))
    "Constants for message type '<set_uvc_light-request>"
  '((:OFF . 0)
    (:ON . 1))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'set_uvc_light-request)))
    "Constants for message type 'set_uvc_light-request"
  '((:OFF . 0)
    (:ON . 1))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_uvc_light-request>) ostream)
  "Serializes a message object of type '<set_uvc_light-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_uvc_light-request>) istream)
  "Deserializes a message object of type '<set_uvc_light-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_uvc_light-request>)))
  "Returns string type for a service object of type '<set_uvc_light-request>"
  "uvc_light/set_uvc_lightRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_uvc_light-request)))
  "Returns string type for a service object of type 'set_uvc_light-request"
  "uvc_light/set_uvc_lightRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_uvc_light-request>)))
  "Returns md5sum for a message object of type '<set_uvc_light-request>"
  "8f77c0161e0f2021493136bb5f3f0e51")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_uvc_light-request)))
  "Returns md5sum for a message object of type 'set_uvc_light-request"
  "8f77c0161e0f2021493136bb5f3f0e51")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_uvc_light-request>)))
  "Returns full string definition for message of type '<set_uvc_light-request>"
  (cl:format cl:nil "uint8 OFF=0~%uint8 ON=1~%uint8 state~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_uvc_light-request)))
  "Returns full string definition for message of type 'set_uvc_light-request"
  (cl:format cl:nil "uint8 OFF=0~%uint8 ON=1~%uint8 state~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_uvc_light-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_uvc_light-request>))
  "Converts a ROS message object to a list"
  (cl:list 'set_uvc_light-request
    (cl:cons ':state (state msg))
))
;//! \htmlinclude set_uvc_light-response.msg.html

(cl:defclass <set_uvc_light-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass set_uvc_light-response (<set_uvc_light-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_uvc_light-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_uvc_light-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name uvc_light-srv:<set_uvc_light-response> is deprecated: use uvc_light-srv:set_uvc_light-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_uvc_light-response>) ostream)
  "Serializes a message object of type '<set_uvc_light-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_uvc_light-response>) istream)
  "Deserializes a message object of type '<set_uvc_light-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_uvc_light-response>)))
  "Returns string type for a service object of type '<set_uvc_light-response>"
  "uvc_light/set_uvc_lightResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_uvc_light-response)))
  "Returns string type for a service object of type 'set_uvc_light-response"
  "uvc_light/set_uvc_lightResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_uvc_light-response>)))
  "Returns md5sum for a message object of type '<set_uvc_light-response>"
  "8f77c0161e0f2021493136bb5f3f0e51")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_uvc_light-response)))
  "Returns md5sum for a message object of type 'set_uvc_light-response"
  "8f77c0161e0f2021493136bb5f3f0e51")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_uvc_light-response>)))
  "Returns full string definition for message of type '<set_uvc_light-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_uvc_light-response)))
  "Returns full string definition for message of type 'set_uvc_light-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_uvc_light-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_uvc_light-response>))
  "Converts a ROS message object to a list"
  (cl:list 'set_uvc_light-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'set_uvc_light)))
  'set_uvc_light-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'set_uvc_light)))
  'set_uvc_light-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_uvc_light)))
  "Returns string type for a service object of type '<set_uvc_light>"
  "uvc_light/set_uvc_light")