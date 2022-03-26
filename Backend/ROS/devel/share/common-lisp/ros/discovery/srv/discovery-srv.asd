
(cl:in-package :asdf)

(defsystem "discovery-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "discover" :depends-on ("_package_discover"))
    (:file "_package_discover" :depends-on ("_package"))
  ))