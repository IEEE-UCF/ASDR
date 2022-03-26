
(cl:in-package :asdf)

(defsystem "rotary_encoder-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "get_rotary_encoder" :depends-on ("_package_get_rotary_encoder"))
    (:file "_package_get_rotary_encoder" :depends-on ("_package"))
  ))