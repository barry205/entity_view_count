<?php

/**
 * Implements hook_views_data().
 */
function entity_view_count_views_data() {

  $data = array();

  foreach (entity_get_info() as $key => $info) {

    if (!$info['fieldable']) {
      continue;
    }

    $data[$info['base table']][$key . '_entity_view_count'] = array(
      'title'  => t('@label\'s view count', array('@label' => $info['label'])),
      'help' => t('Create relationship for sorting the entities by their views amount.'),

      'relationship' => array(
        'handler' => 'views_handler_relationship',
        'base' => 'entity_view_count',
        'field' => $info['entity keys']['id'],
      ),
    );

    $data[$info['base table']][$key . '_entity_view_count_increase'] = array(
      'title'  => t('Increase count for @label', array('@label' => $info['label'])),
      'help' => t('When using field mode instead of rendered entity this field will create an entity view count entry.'),

      'field' => array(
        'handler' => 'EntityViewCountIncreaseCounterHandler',
      ),
    );
  }

  $data['entity_view_count']['order'] = array(
    'title' => t('Entity view count sort results'),
    'help' => t('Sort result by various entity view count settings.'),

    'sort' => array(
      'handler' => 'EntityViewCountSort',
    ),
  );

  return $data;
}