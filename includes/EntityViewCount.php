<?php

/**
 * Class EntityViewCount.
 *
 * Representing views of entities.
 */
class EntityViewCount extends Entity {

  /**
   * @var Integer
   *
   * The identifier of the entity.
   */
  public $id;

  /**
   * @var String
   *
   * The entity type the entry relate to.
   */
  public $entity_type;

  /**
   * @var Integer
   *
   * The entity id the entry relate to.
   */
  public $entity_id;

  /**
   * @var String
   *
   * The entity owner UID.
   */
  public $entity_owner;

  /**
   * @var String
   *
   * The view mode when the entity was viewed.
   */
  public $view_mode;

  /**
   * @var Integer
   *
   * The unix time stamp the entry created.
   */
  public $created;

  /**
   * @var Integer
   *
   * The user ID that the view the entity which the entry relate to.
   */
  public $uid;

}