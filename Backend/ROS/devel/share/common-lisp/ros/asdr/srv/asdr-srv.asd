
(cl:in-package :asdf)

(defsystem "asdr-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "get_state" :depends-on ("_package_get_state"))
    (:file "_package_get_state" :depends-on ("_package"))
    (:file "set_state" :depends-on ("_package_set_state"))
    (:file "_package_set_state" :depends-on ("_package"))
    (:file "set_velocity" :depends-on ("_package_set_velocity"))
    (:file "_package_set_velocity" :depends-on ("_package"))
  ))