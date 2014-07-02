<?php

/**
 * @file
 * Contain a handler that will create an entity view count row for the viewed
 * entity or any other entity that included via a views relationship.
 */

class EntityViewCountIncreaseCounterHandler extends views_handler_field_entity {

  public function construct() {
    parent::construct();
    $this->options['exclude'] = TRUE;
  }

  public function render($render) {
    $wrapper = $wrapper = entity_metadata_wrapper($this->entity_type, $render->{$this->base_field});
    $params = array(
      'entity_type' => $this->entity_type,
      'entity' => $wrapper->value(),
      'view_mode' => '',
      'entity_owner' => $wrapper->getIdentifier(),
    );

    entity_view_count_create($params)->save();

    return t("This field should be exclude from display.");
  }
}