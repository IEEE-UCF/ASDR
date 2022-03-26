;; Auto-generated. Do not edit!


(when (boundp 'rotary_encoder::get_rotary_encoder)
  (if (not (find-package "ROTARY_ENCODER"))
    (make-package "ROTARY_ENCODER"))
  (shadow 'get_rotary_encoder (find-package "ROTARY_ENCODER")))
(unless (find-package "ROTARY_ENCODER::GET_ROTARY_ENCODER")
  (make-package "ROTARY_ENCODER::GET_ROTARY_ENCODER"))
(unless (find-package "ROTARY_ENCODER::GET_ROTARY_ENCODERREQUEST")
  (make-package "ROTARY_ENCODER::GET_ROTARY_ENCODERREQUEST"))
(unless (find-package "ROTARY_ENCODER::GET_ROTARY_ENCODERRESPONSE")
  (make-package "ROTARY_ENCODER::GET_ROTARY_ENCODERRESPONSE"))

(in-package "ROS")





(defclass rotary_encoder::get_rotary_encoderRequest
  :super ros::object
  :slots ())

(defmethod rotary_encoder::get_rotary_encoderRequest
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

(defclass rotary_encoder::get_rotary_encoderResponse
  :super ros::object
  :slots (_position _velocity ))

(defmethod rotary_encoder::get_rotary_encoderResponse
  (:init
   (&key
    ((:position __position) 0.0)
    ((:velocity __velocity) 0.0)
    )
   (send-super :init)
   (setq _position (float __position))
   (setq _velocity (float __velocity))
   self)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:serialization-length
   ()
   (+
    ;; float32 _position
    4
    ;; float32 _velocity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _position
       (sys::poke _position (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _position
     (setq _position (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rotary_encoder::get_rotary_encoder
  :super ros::object
  :slots ())

(setf (get rotary_encoder::get_rotary_encoder :md5sum-) "2cf6c2ef6d4814960f7bd2c448525593")
(setf (get rotary_encoder::get_rotary_encoder :datatype-) "rotary_encoder/get_rotary_encoder")
(setf (get rotary_encoder::get_rotary_encoder :request) rotary_encoder::get_rotary_encoderRequest)
(setf (get rotary_encoder::get_rotary_encoder :response) rotary_encoder::get_rotary_encoderResponse)

(defmethod rotary_encoder::get_rotary_encoderRequest
  (:response () (instance rotary_encoder::get_rotary_encoderResponse :init)))

(setf (get rotary_encoder::get_rotary_encoderRequest :md5sum-) "2cf6c2ef6d4814960f7bd2c448525593")
(setf (get rotary_encoder::get_rotary_encoderRequest :datatype-) "rotary_encoder/get_rotary_encoderRequest")
(setf (get rotary_encoder::get_rotary_encoderRequest :definition-)
      "---
float32 position
float32 velocity
")

(setf (get rotary_encoder::get_rotary_encoderResponse :md5sum-) "2cf6c2ef6d4814960f7bd2c448525593")
(setf (get rotary_encoder::get_rotary_encoderResponse :datatype-) "rotary_encoder/get_rotary_encoderResponse")
(setf (get rotary_encoder::get_rotary_encoderResponse :definition-)
      "---
float32 position
float32 velocity
")



(provide :rotary_encoder/get_rotary_encoder "2cf6c2ef6d4814960f7bd2c448525593")


