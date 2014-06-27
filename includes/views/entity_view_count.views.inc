<?php

/**
 * Implements hook_views_data().
 */
function entity_view_count_views_data() {

  $data['users']['entity_view_count'] = array(
    'title'  => t('User entity view count'),
    'help'  => t('Create relationship for sorting the users by the number of their viewed entities.'),

    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'entity_view_count',
      'field' => 'uid',
    ),
    'sort' => array(
      'handler' => 'EntityUserViewCountSort',
    ),
  );

  foreach (entity_get_info() as $key => $info) {

    if (!$info['fieldable']) {
      continue;
    }

    $data[$info['base table']][$key . '_entity_view_count'] = array(
      'title'  => t('@label\'s view count', array('@label' => $info['label'])),
      'help' => t('Create relationship for sorting the entities by their views number.'),

      'relationship' => array(
        'handler' => 'views_handler_relationship',
        'base' => 'entity_view_count',
        'field' => $info['entity keys']['id'],
      ),

      'sort' => array(
        'handler' => 'EntityViewCountSort',
      ),
    );
  }

  return $data;
}