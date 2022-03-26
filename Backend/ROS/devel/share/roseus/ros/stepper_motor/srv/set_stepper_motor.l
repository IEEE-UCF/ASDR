;; Auto-generated. Do not edit!


(when (boundp 'stepper_motor::set_stepper_motor)
  (if (not (find-package "STEPPER_MOTOR"))
    (make-package "STEPPER_MOTOR"))
  (shadow 'set_stepper_motor (find-package "STEPPER_MOTOR")))
(unless (find-package "STEPPER_MOTOR::SET_STEPPER_MOTOR")
  (make-package "STEPPER_MOTOR::SET_STEPPER_MOTOR"))
(unless (find-package "STEPPER_MOTOR::SET_STEPPER_MOTORREQUEST")
  (make-package "STEPPER_MOTOR::SET_STEPPER_MOTORREQUEST"))
(unless (find-package "STEPPER_MOTOR::SET_STEPPER_MOTORRESPONSE")
  (make-package "STEPPER_MOTOR::SET_STEPPER_MOTORRESPONSE"))

(in-package "ROS")





(defclass stepper_motor::set_stepper_motorRequest
  :super ros::object
  :slots (_velocity ))

(defmethod stepper_motor::set_stepper_motorRequest
  (:init
   (&key
    ((:velocity __velocity) 0.0)
    )
   (send-super :init)
   (setq _velocity (float __velocity))
   self)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:serialization-length
   ()
   (+
    ;; float32 _velocity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass stepper_motor::set_stepper_motorResponse
  :super ros::object
  :slots ())

(defmethod stepper_motor::set_stepper_motorResponse
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

(defclass stepper_motor::set_stepper_motor
  :super ros::object
  :slots ())

(setf (get stepper_motor::set_stepper_motor :md5sum-) "e4ff88b32504f688719a85e0753f63ce")
(setf (get stepper_motor::set_stepper_motor :datatype-) "stepper_motor/set_stepper_motor")
(setf (get stepper_motor::set_stepper_motor :request) stepper_motor::set_stepper_motorRequest)
(setf (get stepper_motor::set_stepper_motor :response) stepper_motor::set_stepper_motorResponse)

(defmethod stepper_motor::set_stepper_motorRequest
  (:response () (instance stepper_motor::set_stepper_motorResponse :init)))

(setf (get stepper_motor::set_stepper_motorRequest :md5sum-) "e4ff88b32504f688719a85e0753f63ce")
(setf (get stepper_motor::set_stepper_motorRequest :datatype-) "stepper_motor/set_stepper_motorRequest")
(setf (get stepper_motor::set_stepper_motorRequest :definition-)
      "float32 velocity
---
")

(setf (get stepper_motor::set_stepper_motorResponse :md5sum-) "e4ff88b32504f688719a85e0753f63ce")
(setf (get stepper_motor::set_stepper_motorResponse :datatype-) "stepper_motor/set_stepper_motorResponse")
(setf (get stepper_motor::set_stepper_motorResponse :definition-)
      "float32 velocity
---
")



(provide :stepper_motor/set_stepper_motor "e4ff88b32504f688719a85e0753f63ce")


