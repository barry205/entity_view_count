<?php

/**
 * @file
 * Contains a sorting handler.
 */

class EntityViewCountSort extends views_handler_sort {

  /**
   * Overrides parent::query().
   */
  function query() {
    $this->ensure_my_table();
  }
}