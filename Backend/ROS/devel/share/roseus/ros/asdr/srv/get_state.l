;; Auto-generated. Do not edit!


(when (boundp 'asdr::get_state)
  (if (not (find-package "ASDR"))
    (make-package "ASDR"))
  (shadow 'get_state (find-package "ASDR")))
(unless (find-package "ASDR::GET_STATE")
  (make-package "ASDR::GET_STATE"))
(unless (find-package "ASDR::GET_STATEREQUEST")
  (make-package "ASDR::GET_STATEREQUEST"))
(unless (find-package "ASDR::GET_STATERESPONSE")
  (make-package "ASDR::GET_STATERESPONSE"))

(in-package "ROS")





(defclass asdr::get_stateRequest
  :super ros::object
  :slots ())

(defmethod asdr::get_stateRequest
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

(defclass asdr::get_stateResponse
  :super ros::object
  :slots (_state ))

(defmethod asdr::get_stateResponse
  (:init
   (&key
    ((:state __state) "")
    )
   (send-super :init)
   (setq _state (string __state))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; string _state
    4 (length _state)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _state
       (write-long (length _state) s) (princ _state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _state
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _state (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass asdr::get_state
  :super ros::object
  :slots ())

(setf (get asdr::get_state :md5sum-) "af6d3a99f0fbeb66d3248fa4b3e675fb")
(setf (get asdr::get_state :datatype-) "asdr/get_state")
(setf (get asdr::get_state :request) asdr::get_stateRequest)
(setf (get asdr::get_state :response) asdr::get_stateResponse)

(defmethod asdr::get_stateRequest
  (:response () (instance asdr::get_stateResponse :init)))

(setf (get asdr::get_stateRequest :md5sum-) "af6d3a99f0fbeb66d3248fa4b3e675fb")
(setf (get asdr::get_stateRequest :datatype-) "asdr/get_stateRequest")
(setf (get asdr::get_stateRequest :definition-)
      "
---
string state
")

(setf (get asdr::get_stateResponse :md5sum-) "af6d3a99f0fbeb66d3248fa4b3e675fb")
(setf (get asdr::get_stateResponse :datatype-) "asdr/get_stateResponse")
(setf (get asdr::get_stateResponse :definition-)
      "
---
string state
")



(provide :asdr/get_state "af6d3a99f0fbeb66d3248fa4b3e675fb")


