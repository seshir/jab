<?php
/**
 * @file
 * hooks for flags in answers_notifications.
 */

/**
 * Implements hook_flag_default_flags().
 */
function answers_notifications_flag_default_flags() {
  $flags = array();
  $flags['subscribe_answers_notifications'] = array(
    'content_type' => 'node',
    'title' => 'Subscribe',
    'global' => '0',
	'types' => array(
      0 => 'answers_question',
    ),
    'flag_short' => 'Subscribe',
    'flag_long' => '',
    'flag_message' => 'You have subscribed',
    'unflag_short' => 'Unsubscribe',
    'unflag_long' => '',
    'unflag_message' => 'You have unsubscribed',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'weight' => 0,
    'show_on_form' => TRUE,
    'access_author' => '',
    'show_on_page' => TRUE,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'answer_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
    'status' => TRUE,
  );
  return $flags;
}
