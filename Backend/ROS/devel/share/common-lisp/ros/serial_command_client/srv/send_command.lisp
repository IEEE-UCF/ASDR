; Auto-generated. Do not edit!


(cl:in-package serial_command_client-srv)


;//! \htmlinclude send_command-request.msg.html

(cl:defclass <send_command-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:fixnum
    :initform 0)
   (buffer
    :reader buffer
    :initarg :buffer
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass send_command-request (<send_command-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_command-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_command-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_command_client-srv:<send_command-request> is deprecated: use serial_command_client-srv:send_command-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <send_command-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_command_client-srv:command-val is deprecated.  Use serial_command_client-srv:command instead.")
  (command m))

(cl:ensure-generic-function 'buffer-val :lambda-list '(m))
(cl:defmethod buffer-val ((m <send_command-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_command_client-srv:buffer-val is deprecated.  Use serial_command_client-srv:buffer instead.")
  (buffer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_command-request>) ostream)
  "Serializes a message object of type '<send_command-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'command)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'buffer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'buffer))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_command-request>) istream)
  "Deserializes a message object of type '<send_command-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'command)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'buffer) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'buffer)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_command-request>)))
  "Returns string type for a service object of type '<send_command-request>"
  "serial_command_client/send_commandRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_command-request)))
  "Returns string type for a service object of type 'send_command-request"
  "serial_command_client/send_commandRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_command-request>)))
  "Returns md5sum for a message object of type '<send_command-request>"
  "6be57eb71fc2c8bb590b1bea40258ebc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_command-request)))
  "Returns md5sum for a message object of type 'send_command-request"
  "6be57eb71fc2c8bb590b1bea40258ebc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_command-request>)))
  "Returns full string definition for message of type '<send_command-request>"
  (cl:format cl:nil "uint8 command~%uint8[] buffer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_command-request)))
  "Returns full string definition for message of type 'send_command-request"
  (cl:format cl:nil "uint8 command~%uint8[] buffer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_command-request>))
  (cl:+ 0
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'buffer) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_command-request>))
  "Converts a ROS message object to a list"
  (cl:list 'send_command-request
    (cl:cons ':command (command msg))
    (cl:cons ':buffer (buffer msg))
))
;//! \htmlinclude send_command-response.msg.html

(cl:defclass <send_command-response> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0)
   (buffer
    :reader buffer
    :initarg :buffer
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass send_command-response (<send_command-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_command-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_command-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_command_client-srv:<send_command-response> is deprecated: use serial_command_client-srv:send_command-response instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <send_command-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_command_client-srv:status-val is deprecated.  Use serial_command_client-srv:status instead.")
  (status m))

(cl:ensure-generic-function 'buffer-val :lambda-list '(m))
(cl:defmethod buffer-val ((m <send_command-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_command_client-srv:buffer-val is deprecated.  Use serial_command_client-srv:buffer instead.")
  (buffer m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<send_command-response>)))
    "Constants for message type '<send_command-response>"
  '((:FAILURE . 0)
    (:SUCCESS . 1))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'send_command-response)))
    "Constants for message type 'send_command-response"
  '((:FAILURE . 0)
    (:SUCCESS . 1))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_command-response>) ostream)
  "Serializes a message object of type '<send_command-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'buffer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'buffer))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_command-response>) istream)
  "Deserializes a message object of type '<send_command-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'buffer) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'buffer)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_command-response>)))
  "Returns string type for a service object of type '<send_command-response>"
  "serial_command_client/send_commandResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_command-response)))
  "Returns string type for a service object of type 'send_command-response"
  "serial_command_client/send_commandResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_command-response>)))
  "Returns md5sum for a message object of type '<send_command-response>"
  "6be57eb71fc2c8bb590b1bea40258ebc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_command-response)))
  "Returns md5sum for a message object of type 'send_command-response"
  "6be57eb71fc2c8bb590b1bea40258ebc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_command-response>)))
  "Returns full string definition for message of type '<send_command-response>"
  (cl:format cl:nil "uint8 FAILURE=0~%uint8 SUCCESS=1~%uint8 status~%uint8[] buffer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_command-response)))
  "Returns full string definition for message of type 'send_command-response"
  (cl:format cl:nil "uint8 FAILURE=0~%uint8 SUCCESS=1~%uint8 status~%uint8[] buffer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_command-response>))
  (cl:+ 0
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'buffer) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_command-response>))
  "Converts a ROS message object to a list"
  (cl:list 'send_command-response
    (cl:cons ':status (status msg))
    (cl:cons ':buffer (buffer msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'send_command)))
  'send_command-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'send_command)))
  'send_command-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_command)))
  "Returns string type for a service object of type '<send_command>"
  "serial_command_client/send_command")