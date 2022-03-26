;; Auto-generated. Do not edit!


(when (boundp 'asdr::set_velocity)
  (if (not (find-package "ASDR"))
    (make-package "ASDR"))
  (shadow 'set_velocity (find-package "ASDR")))
(unless (find-package "ASDR::SET_VELOCITY")
  (make-package "ASDR::SET_VELOCITY"))
(unless (find-package "ASDR::SET_VELOCITYREQUEST")
  (make-package "ASDR::SET_VELOCITYREQUEST"))
(unless (find-package "ASDR::SET_VELOCITYRESPONSE")
  (make-package "ASDR::SET_VELOCITYRESPONSE"))

(in-package "ROS")





(defclass asdr::set_velocityRequest
  :super ros::object
  :slots (_linear _angular ))

(defmethod asdr::set_velocityRequest
  (:init
   (&key
    ((:linear __linear) 0.0)
    ((:angular __angular) 0.0)
    )
   (send-super :init)
   (setq _linear (float __linear))
   (setq _angular (float __angular))
   self)
  (:linear
   (&optional __linear)
   (if __linear (setq _linear __linear)) _linear)
  (:angular
   (&optional __angular)
   (if __angular (setq _angular __angular)) _angular)
  (:serialization-length
   ()
   (+
    ;; float64 _linear
    8
    ;; float64 _angular
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _linear
       (sys::poke _linear (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular
       (sys::poke _angular (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _linear
     (setq _linear (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular
     (setq _angular (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass asdr::set_velocityResponse
  :super ros::object
  :slots ())

(defmethod asdr::set_velocityResponse
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

(defclass asdr::set_velocity
  :super ros::object
  :slots ())

(setf (get asdr::set_velocity :md5sum-) "144a16e4d6b53a0dbadc2e617460a173")
(setf (get asdr::set_velocity :datatype-) "asdr/set_velocity")
(setf (get asdr::set_velocity :request) asdr::set_velocityRequest)
(setf (get asdr::set_velocity :response) asdr::set_velocityResponse)

(defmethod asdr::set_velocityRequest
  (:response () (instance asdr::set_velocityResponse :init)))

(setf (get asdr::set_velocityRequest :md5sum-) "144a16e4d6b53a0dbadc2e617460a173")
(setf (get asdr::set_velocityRequest :datatype-) "asdr/set_velocityRequest")
(setf (get asdr::set_velocityRequest :definition-)
      "float64 linear
float64 angular
---

")

(setf (get asdr::set_velocityResponse :md5sum-) "144a16e4d6b53a0dbadc2e617460a173")
(setf (get asdr::set_velocityResponse :datatype-) "asdr/set_velocityResponse")
(setf (get asdr::set_velocityResponse :definition-)
      "float64 linear
float64 angular
---

")



(provide :asdr/set_velocity "144a16e4d6b53a0dbadc2e617460a173")


