;; Auto-generated. Do not edit!


(when (boundp 'uvc_light::set_uvc_light)
  (if (not (find-package "UVC_LIGHT"))
    (make-package "UVC_LIGHT"))
  (shadow 'set_uvc_light (find-package "UVC_LIGHT")))
(unless (find-package "UVC_LIGHT::SET_UVC_LIGHT")
  (make-package "UVC_LIGHT::SET_UVC_LIGHT"))
(unless (find-package "UVC_LIGHT::SET_UVC_LIGHTREQUEST")
  (make-package "UVC_LIGHT::SET_UVC_LIGHTREQUEST"))
(unless (find-package "UVC_LIGHT::SET_UVC_LIGHTRESPONSE")
  (make-package "UVC_LIGHT::SET_UVC_LIGHTRESPONSE"))

(in-package "ROS")





(intern "*OFF*" (find-package "UVC_LIGHT::SET_UVC_LIGHTREQUEST"))
(shadow '*OFF* (find-package "UVC_LIGHT::SET_UVC_LIGHTREQUEST"))
(defconstant uvc_light::set_uvc_lightRequest::*OFF* 0)
(intern "*ON*" (find-package "UVC_LIGHT::SET_UVC_LIGHTREQUEST"))
(shadow '*ON* (find-package "UVC_LIGHT::SET_UVC_LIGHTREQUEST"))
(defconstant uvc_light::set_uvc_lightRequest::*ON* 1)

(defun uvc_light::set_uvc_lightRequest-to-symbol (const)
  (cond
        ((= const 0) 'uvc_light::set_uvc_lightRequest::*OFF*)
        ((= const 1) 'uvc_light::set_uvc_lightRequest::*ON*)
        (t nil)))

(defclass uvc_light::set_uvc_lightRequest
  :super ros::object
  :slots (_state ))

(defmethod uvc_light::set_uvc_lightRequest
  (:init
   (&key
    ((:state __state) 0)
    )
   (send-super :init)
   (setq _state (round __state))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; uint8 _state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _state
       (write-byte _state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass uvc_light::set_uvc_lightResponse
  :super ros::object
  :slots ())

(defmethod uvc_light::set_uvc_lightResponse
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

(defclass uvc_light::set_uvc_light
  :super ros::object
  :slots ())

(setf (get uvc_light::set_uvc_light :md5sum-) "8f77c0161e0f2021493136bb5f3f0e51")
(setf (get uvc_light::set_uvc_light :datatype-) "uvc_light/set_uvc_light")
(setf (get uvc_light::set_uvc_light :request) uvc_light::set_uvc_lightRequest)
(setf (get uvc_light::set_uvc_light :response) uvc_light::set_uvc_lightResponse)

(defmethod uvc_light::set_uvc_lightRequest
  (:response () (instance uvc_light::set_uvc_lightResponse :init)))

(setf (get uvc_light::set_uvc_lightRequest :md5sum-) "8f77c0161e0f2021493136bb5f3f0e51")
(setf (get uvc_light::set_uvc_lightRequest :datatype-) "uvc_light/set_uvc_lightRequest")
(setf (get uvc_light::set_uvc_lightRequest :definition-)
      "uint8 OFF=0
uint8 ON=1
uint8 state
---
")

(setf (get uvc_light::set_uvc_lightResponse :md5sum-) "8f77c0161e0f2021493136bb5f3f0e51")
(setf (get uvc_light::set_uvc_lightResponse :datatype-) "uvc_light/set_uvc_lightResponse")
(setf (get uvc_light::set_uvc_lightResponse :definition-)
      "uint8 OFF=0
uint8 ON=1
uint8 state
---
")



(provide :uvc_light/set_uvc_light "8f77c0161e0f2021493136bb5f3f0e51")


