; Auto-generated. Do not edit!


(cl:in-package rotary_encoder-srv)


;//! \htmlinclude get_rotary_encoder-request.msg.html

(cl:defclass <get_rotary_encoder-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass get_rotary_encoder-request (<get_rotary_encoder-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <get_rotary_encoder-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'get_rotary_encoder-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rotary_encoder-srv:<get_rotary_encoder-request> is deprecated: use rotary_encoder-srv:get_rotary_encoder-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <get_rotary_encoder-request>) ostream)
  "Serializes a message object of type '<get_rotary_encoder-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <get_rotary_encoder-request>) istream)
  "Deserializes a message object of type '<get_rotary_encoder-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<get_rotary_encoder-request>)))
  "Returns string type for a service object of type '<get_rotary_encoder-request>"
  "rotary_encoder/get_rotary_encoderRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'get_rotary_encoder-request)))
  "Returns string type for a service object of type 'get_rotary_encoder-request"
  "rotary_encoder/get_rotary_encoderRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<get_rotary_encoder-request>)))
  "Returns md5sum for a message object of type '<get_rotary_encoder-request>"
  "2cf6c2ef6d4814960f7bd2c448525593")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'get_rotary_encoder-request)))
  "Returns md5sum for a message object of type 'get_rotary_encoder-request"
  "2cf6c2ef6d4814960f7bd2c448525593")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<get_rotary_encoder-request>)))
  "Returns full string definition for message of type '<get_rotary_encoder-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'get_rotary_encoder-request)))
  "Returns full string definition for message of type 'get_rotary_encoder-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <get_rotary_encoder-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <get_rotary_encoder-request>))
  "Converts a ROS message object to a list"
  (cl:list 'get_rotary_encoder-request
))
;//! \htmlinclude get_rotary_encoder-response.msg.html

(cl:defclass <get_rotary_encoder-response> (roslisp-msg-protocol:ros-message)
  ((position
    :reader position
    :initarg :position
    :type cl:float
    :initform 0.0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0))
)

(cl:defclass get_rotary_encoder-response (<get_rotary_encoder-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <get_rotary_encoder-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'get_rotary_encoder-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rotary_encoder-srv:<get_rotary_encoder-response> is deprecated: use rotary_encoder-srv:get_rotary_encoder-response instead.")))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <get_rotary_encoder-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rotary_encoder-srv:position-val is deprecated.  Use rotary_encoder-srv:position instead.")
  (position m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <get_rotary_encoder-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rotary_encoder-srv:velocity-val is deprecated.  Use rotary_encoder-srv:velocity instead.")
  (velocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <get_rotary_encoder-response>) ostream)
  "Serializes a message object of type '<get_rotary_encoder-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'position))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <get_rotary_encoder-response>) istream)
  "Deserializes a message object of type '<get_rotary_encoder-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<get_rotary_encoder-response>)))
  "Returns string type for a service object of type '<get_rotary_encoder-response>"
  "rotary_encoder/get_rotary_encoderResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'get_rotary_encoder-response)))
  "Returns string type for a service object of type 'get_rotary_encoder-response"
  "rotary_encoder/get_rotary_encoderResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<get_rotary_encoder-response>)))
  "Returns md5sum for a message object of type '<get_rotary_encoder-response>"
  "2cf6c2ef6d4814960f7bd2c448525593")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'get_rotary_encoder-response)))
  "Returns md5sum for a message object of type 'get_rotary_encoder-response"
  "2cf6c2ef6d4814960f7bd2c448525593")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<get_rotary_encoder-response>)))
  "Returns full string definition for message of type '<get_rotary_encoder-response>"
  (cl:format cl:nil "float32 position~%float32 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'get_rotary_encoder-response)))
  "Returns full string definition for message of type 'get_rotary_encoder-response"
  (cl:format cl:nil "float32 position~%float32 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <get_rotary_encoder-response>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <get_rotary_encoder-response>))
  "Converts a ROS message object to a list"
  (cl:list 'get_rotary_encoder-response
    (cl:cons ':position (position msg))
    (cl:cons ':velocity (velocity msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'get_rotary_encoder)))
  'get_rotary_encoder-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'get_rotary_encoder)))
  'get_rotary_encoder-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'get_rotary_encoder)))
  "Returns string type for a service object of type '<get_rotary_encoder>"
  "rotary_encoder/get_rotary_encoder")