<?php

/**
 * @file
 * Contains a sorting handler for sort the results by the time the entity was
 * viewed.
 */

class EntityViewCountSort extends views_handler_sort {

  /**
   * Overrides parent::query().
   */
  function query() {
    $this->ensure_my_table();

    $this->query->orderby[] = array(
      'field' => "(SELECT count(*) FROM `entity_view_count` WHERE entity_id = " . $this->table_alias . "." . $this->view->base_field . ")",
      'direction' => $this->options['order'],
    );
  }

}