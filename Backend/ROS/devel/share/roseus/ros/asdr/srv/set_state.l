;; Auto-generated. Do not edit!


(when (boundp 'asdr::set_state)
  (if (not (find-package "ASDR"))
    (make-package "ASDR"))
  (shadow 'set_state (find-package "ASDR")))
(unless (find-package "ASDR::SET_STATE")
  (make-package "ASDR::SET_STATE"))
(unless (find-package "ASDR::SET_STATEREQUEST")
  (make-package "ASDR::SET_STATEREQUEST"))
(unless (find-package "ASDR::SET_STATERESPONSE")
  (make-package "ASDR::SET_STATERESPONSE"))

(in-package "ROS")





(defclass asdr::set_stateRequest
  :super ros::object
  :slots (_state ))

(defmethod asdr::set_stateRequest
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

(defclass asdr::set_stateResponse
  :super ros::object
  :slots ())

(defmethod asdr::set_stateResponse
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

(defclass asdr::set_state
  :super ros::object
  :slots ())

(setf (get asdr::set_state :md5sum-) "af6d3a99f0fbeb66d3248fa4b3e675fb")
(setf (get asdr::set_state :datatype-) "asdr/set_state")
(setf (get asdr::set_state :request) asdr::set_stateRequest)
(setf (get asdr::set_state :response) asdr::set_stateResponse)

(defmethod asdr::set_stateRequest
  (:response () (instance asdr::set_stateResponse :init)))

(setf (get asdr::set_stateRequest :md5sum-) "af6d3a99f0fbeb66d3248fa4b3e675fb")
(setf (get asdr::set_stateRequest :datatype-) "asdr/set_stateRequest")
(setf (get asdr::set_stateRequest :definition-)
      "string state
---

")

(setf (get asdr::set_stateResponse :md5sum-) "af6d3a99f0fbeb66d3248fa4b3e675fb")
(setf (get asdr::set_stateResponse :datatype-) "asdr/set_stateResponse")
(setf (get asdr::set_stateResponse :definition-)
      "string state
---

")



(provide :asdr/set_state "af6d3a99f0fbeb66d3248fa4b3e675fb")


