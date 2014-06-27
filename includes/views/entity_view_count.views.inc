<?php

/**
 * Implements hook_views_data().
 */
function entity_view_count_views_data() {

  $data['users']['entity_view_count'] = array(
    'title'  => t('users viewed entity'),
    'help' => t('Order the users by the number of their viewed posts.'),

    'relationship' => array(
      'title' => t('Entity view count'),
      'label'  => t('Entity view count: users viewed entity'),
      'help' => t('Order the users by the number of their viewed posts.'),
      'handler' => 'views_handler_relationship',
      'base' => 'entity_view_count',
      'field' => 'uid',
    ),
    'sort' => array(
      'handler' => 'EntityViewCountSort',
    ),
  );

  return $data;
}