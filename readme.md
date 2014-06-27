[![Build Status](https://travis-ci.org/DrupalHub/entity_view_count.svg?branch=7.x-1.x)](https://travis-ci.org/DrupalHub/entity_view_count)

Entity view count
=========
The entity view count designed tracking views of entities. Unlike the
[Node view count](http://www.drupal.org/project/node_view_count), Entity view
count can track views of entity for a specific view modes and can also display
how much the users entities viewed for a specific user.

Instructions
========
Install the module like any other module. By default the module track any full
view mode display of any entity. You can change that in
admin/config/system/entity_view_count.

Features
========
if you'd like to display info for given node or entity you can attache the field
 "Entity view count". The field have two formats:

* Entity view count default - This formatter will display how many time the
  entity was viewed by any one.
* User entities view count - This formatter can be attached only for a user
  entity. This will display how many times the user's entities was viewed i.e:
  how many times the user's nodes, comments, and terms was viewed by any user.
* When displaying a list of users you can sort the users by the number of their
  viewed entities.