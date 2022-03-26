; Auto-generated. Do not edit!


(cl:in-package coverage_path_planner-srv)


;//! \htmlinclude make_plan-request.msg.html

(cl:defclass <make_plan-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass make_plan-request (<make_plan-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <make_plan-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'make_plan-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name coverage_path_planner-srv:<make_plan-request> is deprecated: use coverage_path_planner-srv:make_plan-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <make_plan-request>) ostream)
  "Serializes a message object of type '<make_plan-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <make_plan-request>) istream)
  "Deserializes a message object of type '<make_plan-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<make_plan-request>)))
  "Returns string type for a service object of type '<make_plan-request>"
  "coverage_path_planner/make_planRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'make_plan-request)))
  "Returns string type for a service object of type 'make_plan-request"
  "coverage_path_planner/make_planRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<make_plan-request>)))
  "Returns md5sum for a message object of type '<make_plan-request>"
  "89526be3bcb6a9380bfd5badd496049d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'make_plan-request)))
  "Returns md5sum for a message object of type 'make_plan-request"
  "89526be3bcb6a9380bfd5badd496049d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<make_plan-request>)))
  "Returns full string definition for message of type '<make_plan-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'make_plan-request)))
  "Returns full string definition for message of type 'make_plan-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <make_plan-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <make_plan-request>))
  "Converts a ROS message object to a list"
  (cl:list 'make_plan-request
))
;//! \htmlinclude make_plan-response.msg.html

(cl:defclass <make_plan-response> (roslisp-msg-protocol:ros-message)
  ((plan
    :reader plan
    :initarg :plan
    :type (cl:vector geometry_msgs-msg:Pose)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Pose :initial-element (cl:make-instance 'geometry_msgs-msg:Pose))))
)

(cl:defclass make_plan-response (<make_plan-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <make_plan-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'make_plan-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name coverage_path_planner-srv:<make_plan-response> is deprecated: use coverage_path_planner-srv:make_plan-response instead.")))

(cl:ensure-generic-function 'plan-val :lambda-list '(m))
(cl:defmethod plan-val ((m <make_plan-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader coverage_path_planner-srv:plan-val is deprecated.  Use coverage_path_planner-srv:plan instead.")
  (plan m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <make_plan-response>) ostream)
  "Serializes a message object of type '<make_plan-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'plan))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'plan))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <make_plan-response>) istream)
  "Deserializes a message object of type '<make_plan-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'plan) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'plan)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Pose))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<make_plan-response>)))
  "Returns string type for a service object of type '<make_plan-response>"
  "coverage_path_planner/make_planResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'make_plan-response)))
  "Returns string type for a service object of type 'make_plan-response"
  "coverage_path_planner/make_planResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<make_plan-response>)))
  "Returns md5sum for a message object of type '<make_plan-response>"
  "89526be3bcb6a9380bfd5badd496049d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'make_plan-response)))
  "Returns md5sum for a message object of type 'make_plan-response"
  "89526be3bcb6a9380bfd5badd496049d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<make_plan-response>)))
  "Returns full string definition for message of type '<make_plan-response>"
  (cl:format cl:nil "geometry_msgs/Pose[] plan~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'make_plan-response)))
  "Returns full string definition for message of type 'make_plan-response"
  (cl:format cl:nil "geometry_msgs/Pose[] plan~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <make_plan-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'plan) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <make_plan-response>))
  "Converts a ROS message object to a list"
  (cl:list 'make_plan-response
    (cl:cons ':plan (plan msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'make_plan)))
  'make_plan-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'make_plan)))
  'make_plan-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'make_plan)))
  "Returns string type for a service object of type '<make_plan>"
  "coverage_path_planner/make_plan")