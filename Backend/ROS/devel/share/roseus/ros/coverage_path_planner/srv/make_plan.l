;; Auto-generated. Do not edit!


(when (boundp 'coverage_path_planner::make_plan)
  (if (not (find-package "COVERAGE_PATH_PLANNER"))
    (make-package "COVERAGE_PATH_PLANNER"))
  (shadow 'make_plan (find-package "COVERAGE_PATH_PLANNER")))
(unless (find-package "COVERAGE_PATH_PLANNER::MAKE_PLAN")
  (make-package "COVERAGE_PATH_PLANNER::MAKE_PLAN"))
(unless (find-package "COVERAGE_PATH_PLANNER::MAKE_PLANREQUEST")
  (make-package "COVERAGE_PATH_PLANNER::MAKE_PLANREQUEST"))
(unless (find-package "COVERAGE_PATH_PLANNER::MAKE_PLANRESPONSE")
  (make-package "COVERAGE_PATH_PLANNER::MAKE_PLANRESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass coverage_path_planner::make_planRequest
  :super ros::object
  :slots ())

(defmethod coverage_path_planner::make_planRequest
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

(defclass coverage_path_planner::make_planResponse
  :super ros::object
  :slots (_plan ))

(defmethod coverage_path_planner::make_planResponse
  (:init
   (&key
    ((:plan __plan) ())
    )
   (send-super :init)
   (setq _plan __plan)
   self)
  (:plan
   (&rest __plan)
   (if (keywordp (car __plan))
       (send* _plan __plan)
     (progn
       (if __plan (setq _plan (car __plan)))
       _plan)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose[] _plan
    (apply #'+ (send-all _plan :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose[] _plan
     (write-long (length _plan) s)
     (dolist (elem _plan)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose[] _plan
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _plan (let (r) (dotimes (i n) (push (instance geometry_msgs::Pose :init) r)) r))
     (dolist (elem- _plan)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(defclass coverage_path_planner::make_plan
  :super ros::object
  :slots ())

(setf (get coverage_path_planner::make_plan :md5sum-) "89526be3bcb6a9380bfd5badd496049d")
(setf (get coverage_path_planner::make_plan :datatype-) "coverage_path_planner/make_plan")
(setf (get coverage_path_planner::make_plan :request) coverage_path_planner::make_planRequest)
(setf (get coverage_path_planner::make_plan :response) coverage_path_planner::make_planResponse)

(defmethod coverage_path_planner::make_planRequest
  (:response () (instance coverage_path_planner::make_planResponse :init)))

(setf (get coverage_path_planner::make_planRequest :md5sum-) "89526be3bcb6a9380bfd5badd496049d")
(setf (get coverage_path_planner::make_planRequest :datatype-) "coverage_path_planner/make_planRequest")
(setf (get coverage_path_planner::make_planRequest :definition-)
      "---
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
")

(setf (get coverage_path_planner::make_planResponse :md5sum-) "89526be3bcb6a9380bfd5badd496049d")
(setf (get coverage_path_planner::make_planResponse :datatype-) "coverage_path_planner/make_planResponse")
(setf (get coverage_path_planner::make_planResponse :definition-)
      "---
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
")



(provide :coverage_path_planner/make_plan "89526be3bcb6a9380bfd5badd496049d")


