<?php

/*
Examples from http://drupal.org/node/126522:
*/

/*

Stored field example.

Parameters:
&$entity_field - The computed field. Used to store the computed value.
$entity_type - The entity type: node, user, comment, etc.
$entity - The actual entity (a node, user, comment, etc.)
$field - General field settings.
$instance - Field instance settings.
$items - The list of items.

*/
function computed_field_YOUR_FIELD_MACHINE_NAME_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $entity_field[0]['value'] = 'value';
}


/*

View field example.

*/
function computed_field_YOUR_FIELD_MACHINE_NAME_display($field, $entity_field_item, $entity_lang, $langcode) {
  return '$' . number_format($entity_field_item['value'], 2);
}
?>
