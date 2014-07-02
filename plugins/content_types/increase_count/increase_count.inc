<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Increase count'),
  'description' => t('Increase the view count of the entity.'),
  'category' => 'Entity view count',
);

/**
 * Render callback.
 */
function entity_view_count_increase_count_content_type_render($subtype, $conf, $args, $context) {
  $item = menu_get_item();

  $entity_type = $entity = NULL;

  switch ($item['path']) {
    case 'node/%':
      $entity_type = 'node';
      $entity = $item['map'][1];
      break;

    case 'user/%':
      $entity_type = 'user';
      $entity = $item['map'][1];
      break;

    case 'taxonomy/term/%':
      $entity_type = 'taxonomy_term';
      $entity = $item['map'][2];
      break;
  }

  $params = array(
    'entity_type' => $entity_type,
    'entity' => $entity,
    'view_mode' => '',
    'entity_owner' => !empty($entity->uid) ? $entity->uid : 0,
  );

  entity_view_count_create($params)->save();
}