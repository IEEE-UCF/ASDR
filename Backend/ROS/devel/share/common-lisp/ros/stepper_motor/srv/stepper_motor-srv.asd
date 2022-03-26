
(cl:in-package :asdf)

(defsystem "stepper_motor-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "set_stepper_motor" :depends-on ("_package_set_stepper_motor"))
    (:file "_package_set_stepper_motor" :depends-on ("_package"))
  ))