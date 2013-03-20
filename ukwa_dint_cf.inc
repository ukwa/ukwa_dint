<?php

/* Utility functions, integrating with other services */

define('UKWA_CRAWL_WAYBACK', "http://opera.bl.uk:8080/wayback/");
define('UKWA_OPEN_WAYBACK', "http://www.webarchive.org.uk/wayback/archive/");

define('WAYBACK_URLQUERY', "xmlquery.jsp?url=");
define('WAYBACK_PREFIXQUERY', "xmlquery.jsp?type=prefixquery&url=");

/**
 * test
 */
function ukwa_test() {
  print "TEST OK";
}

function ukwa_crawled_urls($url) {
   $num = ukwa_crawled_url_prefix_count($url);
   return "<a title=\"Crawled URLs starting with ".$url."\" href=\"".UKWA_CRAWL_WAYBACK."*/".$url."\">".$num."</a>";
}
function ukwa_crawled_url_prefix_count($url) {
   $wayback_url = UKWA_CRAWL_WAYBACK.WAYBACK_PREFIXQUERY.$url;
   $wxml = simplexml_load_file($wayback_url);
   $num = $wxml->request->numresults;
   if( $num == "" ) $num = 0;
   return $num;
}
function ukwa_open_urls($url) {

}

/* 
Computed Fields.
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

function computed_field_field_crawl_status_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  dpm($entity);
  $entity_field[0]['value'] = $entity->field_url;
}

function computed_field_field_crawl_status_display($field, $entity_field_item, $entity_lang, $langcode) {
  dpm($entity_field_item['value']);
  $url = $entity_field_item['value']['und'][0]['url'];
  return ukwa_crawled_urls($url)." URLs during the last crawl.";
}

?>
