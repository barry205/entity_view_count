<?php

/**
 * Class EntityViewCountController
 *
 * Holds the controller for the entity view count module.
 */
class EntityViewCountController {

  /**
   * Check if the entity was already viewed.
   *
   * @param EntityMetadataWrapper $wrapper
   *  The entity wrapper.
   * @param integer $timestamp
   *  The timestamp we need to check if the entity was viewed.
   *
   * @return boolean
   */
  public static function viewed(EntityMetadataWrapper $wrapper, $timestamp = NULL) {
  }
}