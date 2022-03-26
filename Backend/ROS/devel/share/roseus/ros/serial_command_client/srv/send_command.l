;; Auto-generated. Do not edit!


(when (boundp 'serial_command_client::send_command)
  (if (not (find-package "SERIAL_COMMAND_CLIENT"))
    (make-package "SERIAL_COMMAND_CLIENT"))
  (shadow 'send_command (find-package "SERIAL_COMMAND_CLIENT")))
(unless (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMAND")
  (make-package "SERIAL_COMMAND_CLIENT::SEND_COMMAND"))
(unless (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDREQUEST")
  (make-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDREQUEST"))
(unless (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDRESPONSE")
  (make-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDRESPONSE"))

(in-package "ROS")





(defclass serial_command_client::send_commandRequest
  :super ros::object
  :slots (_command _buffer ))

(defmethod serial_command_client::send_commandRequest
  (:init
   (&key
    ((:command __command) 0)
    ((:buffer __buffer) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _command (round __command))
   (setq _buffer __buffer)
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:buffer
   (&optional __buffer)
   (if __buffer (setq _buffer __buffer)) _buffer)
  (:serialization-length
   ()
   (+
    ;; uint8 _command
    1
    ;; uint8[] _buffer
    (* 1    (length _buffer)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _command
       (write-byte _command s)
     ;; uint8[] _buffer
     (write-long (length _buffer) s)
     (princ _buffer s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _command
     (setq _command (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _buffer
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _buffer (make-array n :element-type :char))
     (replace _buffer buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(intern "*FAILURE*" (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDRESPONSE"))
(shadow '*FAILURE* (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDRESPONSE"))
(defconstant serial_command_client::send_commandResponse::*FAILURE* 0)
(intern "*SUCCESS*" (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDRESPONSE"))
(shadow '*SUCCESS* (find-package "SERIAL_COMMAND_CLIENT::SEND_COMMANDRESPONSE"))
(defconstant serial_command_client::send_commandResponse::*SUCCESS* 1)

(defun serial_command_client::send_commandResponse-to-symbol (const)
  (cond
        ((= const 0) 'serial_command_client::send_commandResponse::*FAILURE*)
        ((= const 1) 'serial_command_client::send_commandResponse::*SUCCESS*)
        (t nil)))

(defclass serial_command_client::send_commandResponse
  :super ros::object
  :slots (_status _buffer ))

(defmethod serial_command_client::send_commandResponse
  (:init
   (&key
    ((:status __status) 0)
    ((:buffer __buffer) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _status (round __status))
   (setq _buffer __buffer)
   self)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:buffer
   (&optional __buffer)
   (if __buffer (setq _buffer __buffer)) _buffer)
  (:serialization-length
   ()
   (+
    ;; uint8 _status
    1
    ;; uint8[] _buffer
    (* 1    (length _buffer)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _status
       (write-byte _status s)
     ;; uint8[] _buffer
     (write-long (length _buffer) s)
     (princ _buffer s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _status
     (setq _status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _buffer
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _buffer (make-array n :element-type :char))
     (replace _buffer buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(defclass serial_command_client::send_command
  :super ros::object
  :slots ())

(setf (get serial_command_client::send_command :md5sum-) "6be57eb71fc2c8bb590b1bea40258ebc")
(setf (get serial_command_client::send_command :datatype-) "serial_command_client/send_command")
(setf (get serial_command_client::send_command :request) serial_command_client::send_commandRequest)
(setf (get serial_command_client::send_command :response) serial_command_client::send_commandResponse)

(defmethod serial_command_client::send_commandRequest
  (:response () (instance serial_command_client::send_commandResponse :init)))

(setf (get serial_command_client::send_commandRequest :md5sum-) "6be57eb71fc2c8bb590b1bea40258ebc")
(setf (get serial_command_client::send_commandRequest :datatype-) "serial_command_client/send_commandRequest")
(setf (get serial_command_client::send_commandRequest :definition-)
      "uint8 command
uint8[] buffer
---
uint8 FAILURE=0
uint8 SUCCESS=1
uint8 status
uint8[] buffer
")

(setf (get serial_command_client::send_commandResponse :md5sum-) "6be57eb71fc2c8bb590b1bea40258ebc")
(setf (get serial_command_client::send_commandResponse :datatype-) "serial_command_client/send_commandResponse")
(setf (get serial_command_client::send_commandResponse :definition-)
      "uint8 command
uint8[] buffer
---
uint8 FAILURE=0
uint8 SUCCESS=1
uint8 status
uint8[] buffer
")



(provide :serial_command_client/send_command "6be57eb71fc2c8bb590b1bea40258ebc")


