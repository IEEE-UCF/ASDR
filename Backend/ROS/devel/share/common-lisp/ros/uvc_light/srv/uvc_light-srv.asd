
(cl:in-package :asdf)

(defsystem "uvc_light-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "set_uvc_light" :depends-on ("_package_set_uvc_light"))
    (:file "_package_set_uvc_light" :depends-on ("_package"))
  ))