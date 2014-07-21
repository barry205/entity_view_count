<?php

/**
 * @file
 * Holds all that relate to field api.
 *
 * Although this is not a normal field we need an easy way to display
 * information about the given entity. Create field that will return the value
 * of the views is the right solution for that.
 */

/**
 * Implements hook_field_info().
 */
function entity_view_count_field_info() {
  return array(
    'entity_view_count' => array(
      'label' => t('Entity view count'),
      'description' => t('Provide info about the entity from entity view count table'),
      'default_widget' => 'default',
      'default_formatter' => 'default',
    ),
  );
}

/**
 * Implements hook_field_widget_info().
 */
function entity_view_count_field_widget_info() {
  return array(
    'default' => array(
      'label' => t('Entity view count'),
      'field types' => array('entity_view_count'),
    ),
  );
}

/**
 * Implements hook_field_formatter_info().
 */
function entity_view_count_field_formatter_info() {
  return array(
    'default' => array(
      'label' => t('Entity view count default'),
      'field types' => array('entity_view_count'),
    ),
    'user_viewing_entities' => array(
      'label' => t('User entities view count'),
      'field types' => array('entity_view_count'),
    ),
    'user_owned_entities_viewed' => array(
      'label' => t('User entity\'s views'),
      'field types' => array('entity_view_count'),
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function entity_view_count_field_is_empty($item, $field) {
  return FALSE;
}

/**
 * Implements hook_field_prepare_view().
 */
function entity_view_count_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  if ($field['type'] != 'entity_view_count') {
    return;
  }

  foreach ($entities as $id => $entity) {
    if (empty($items[$id])) {
      $items[$id][0] = $entity;
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function entity_view_count_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  if (!user_access('view entity view count field')) {
    return array();
  }

  $wrapper = entity_metadata_wrapper($entity_type, $entity);

  switch ($display['type']) {

    case 'user_owned_entities_viewed':
      $result = entity_view_count_user_owned_entity_count($entity->uid);
      break;

    case 'user_viewing_entities':
      if ($wrapper->type() != 'user') {
        drupal_set_message(t('The formatter "User entities view count" can by applied only to user'), 'warning');
        return array();
      }

      $result = entity_view_count_user_viewing_entities_count($wrapper->getIdentifier());
      break;

    case 'default':
    default:
      $result = entity_view_count_get_entity_count($entity_type, $wrapper->getIdentifier());
      break;
  }

  return array(
    '0' => array('#markup' => $result),
  );
}
