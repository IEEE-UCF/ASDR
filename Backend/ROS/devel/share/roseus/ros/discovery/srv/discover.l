;; Auto-generated. Do not edit!


(when (boundp 'discovery::discover)
  (if (not (find-package "DISCOVERY"))
    (make-package "DISCOVERY"))
  (shadow 'discover (find-package "DISCOVERY")))
(unless (find-package "DISCOVERY::DISCOVER")
  (make-package "DISCOVERY::DISCOVER"))
(unless (find-package "DISCOVERY::DISCOVERREQUEST")
  (make-package "DISCOVERY::DISCOVERREQUEST"))
(unless (find-package "DISCOVERY::DISCOVERRESPONSE")
  (make-package "DISCOVERY::DISCOVERRESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass discovery::discoverRequest
  :super ros::object
  :slots ())

(defmethod discovery::discoverRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(intern "*FAILURE*" (find-package "DISCOVERY::DISCOVERRESPONSE"))
(shadow '*FAILURE* (find-package "DISCOVERY::DISCOVERRESPONSE"))
(defconstant discovery::discoverResponse::*FAILURE* 0)
(intern "*SUCCESS*" (find-package "DISCOVERY::DISCOVERRESPONSE"))
(shadow '*SUCCESS* (find-package "DISCOVERY::DISCOVERRESPONSE"))
(defconstant discovery::discoverResponse::*SUCCESS* 1)

(defun discovery::discoverResponse-to-symbol (const)
  (cond
        ((= const 0) 'discovery::discoverResponse::*FAILURE*)
        ((= const 1) 'discovery::discoverResponse::*SUCCESS*)
        (t nil)))

(defclass discovery::discoverResponse
  :super ros::object
  :slots (_status _pose ))

(defmethod discovery::discoverResponse
  (:init
   (&key
    ((:status __status) 0)
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _status (round __status))
   (setq _pose __pose)
   self)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:serialization-length
   ()
   (+
    ;; uint8 _status
    1
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _status
       (write-byte _status s)
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _status
     (setq _status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;;
   self)
  )

(defclass discovery::discover
  :super ros::object
  :slots ())

(setf (get discovery::discover :md5sum-) "92972308c7fadb3f91e8ad956494a137")
(setf (get discovery::discover :datatype-) "discovery/discover")
(setf (get discovery::discover :request) discovery::discoverRequest)
(setf (get discovery::discover :response) discovery::discoverResponse)

(defmethod discovery::discoverRequest
  (:response () (instance discovery::discoverResponse :init)))

(setf (get discovery::discoverRequest :md5sum-) "92972308c7fadb3f91e8ad956494a137")
(setf (get discovery::discoverRequest :datatype-) "discovery/discoverRequest")
(setf (get discovery::discoverRequest :definition-)
      "---
uint8 FAILURE=0
uint8 SUCCESS=1
uint8 status
geometry_msgs/Pose pose

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
")

(setf (get discovery::discoverResponse :md5sum-) "92972308c7fadb3f91e8ad956494a137")
(setf (get discovery::discoverResponse :datatype-) "discovery/discoverResponse")
(setf (get discovery::discoverResponse :definition-)
      "---
uint8 FAILURE=0
uint8 SUCCESS=1
uint8 status
geometry_msgs/Pose pose

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
")



(provide :discovery/discover "92972308c7fadb3f91e8ad956494a137")


