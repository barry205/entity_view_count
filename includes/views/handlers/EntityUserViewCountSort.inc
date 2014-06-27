<?php

/**
 * @file
 * Contains a sorting handler for sort the users by the number of their viewed
 * entities.
 */

class EntityUserViewCountSort extends views_handler_sort {

  /**
   * Overrides parent::query().
   */
  function query() {
    $this->ensure_my_table();

    $this->query->orderby[] = array(
      'field' => "(SELECT count(*) FROM `entity_view_count` WHERE uid = users.uid)",
      'direction' => $this->options['order'],
    );
  }

}