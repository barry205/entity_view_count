<?php

/**
 * @file
 * Holds the class for generate any given entity.
 */

class EntityGenerator {

  /**
   * @var \Entity
   *
   * The entity wrapped with entity metadata wrapper.
   */
  protected $entity;

  /**
   * @var Array
   *
   * The entity info.
   */
  protected $info;

  /**
   * Constructing the class.
   *
   * @param $type
   *  The entity type that we need to construct.
   */
  public function __construct($type) {
    $this->info = entity_get_info($type);
    $table = drupal_get_schema($this->info['base table']);
    $values = array();

    // Set the type if needed.
    if (!empty($this->info['bundles'])) {
      $values[$this->info['entity keys']['bundle']] = array_rand($this->info['bundles']);
    }

    // Set the label of needed.
    if (!empty($this->info['entity keys']['label'])) {
      $values[$this->info['entity keys']['label']] = $this->GenerateValue($table['fields'][$this->info['entity keys']['label']]['type']);
    }

    // Set an owner for the entity.
    if (in_array('uid', $this->info['schema_fields_sql']['base table'])) {
      $uids = array_keys(entity_load('user'));
      $uid = array_rand($uids);

      $values['uid'] = $uid;
    }

    $this->entity = entity_create($type, $values);
    dpm($this->entity);
  }

  /**
   * Generate value for a given value.
   *
   * @param $type
   *  The type of the property.
   *
   * @return $this.
   */
  private function GenerateValue($type) {
    $chars = array('a','b','c','d','e','f','g','h','j','k','l','m','n','o','p','q','r','s','t','u','v','x','y','z');
    switch ($type) {
      case 'int':
      case 'float':
      case 'numeric':
        return rand(0, 8);
        break;
      case 'varchar':
      case 'text':
        $keys = array_rand($chars, 5);
        $word = '';
        foreach ($keys as $key) {
          $word .= $chars[$key];
        }
        return $word;
        break;
      case 'char':
        $key = array_rand($chars);
        return $chars[$key];
        break;
      case 'blob':
        // todo: leave this for later.
        break;
    }
    return $this;
  }

  /**
   * Generate fields for the new entity object using the devel generate module.
   *
   * @return $this
   */
  public function GenerateFields() {

    // Attach field and their values. Using devel_generate for that.
    module_load_include('inc', 'devel_generate', 'devel_generate.fields');
//    devel_generate_fields($this->wrapper->value(), $this->wrapper->type(), $this->wrapper->getBundle());

    return $this;
  }

  /**
   * Save the object to the DB.
   *
   * @return $this.
   */
  public function save() {
    $this->entity->save();
  }
}