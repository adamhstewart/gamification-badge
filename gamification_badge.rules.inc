<?php
/**
 * @file
 * Provides Rules for the Gamification Badge Module
 *
 */

function gamification_badge_rules_event_info() {
  return array(
    'achievements_unlocked_event' => array(
      'label'  => t('An achievement is unlocked'),
      'group' => t('Achievement'),
      'variables'   => array(
        'achievements_unlocked' => array(
          'type' => 'achievements_unlocked',
          'label' => t('Achievement Unlocked'),
        ),
      ),
    ),
  );
}

/**
* Implementation of hook_rules_condition_info().

function gamification_badge_rules_condition_info() {
  return array(
    'achievements_unlocked_condition' => array(
      'group' => t('Achievement'),
      'label' => t('The achievement that was unlocked'),
      'variables' => array(
         'achievements_unlocked' => array(
          'type' => 'achievements_unlocked',
          'label' => t('Achievement Unlocked'),
          ),
      ),
      'module' => 'gamification_badge',
    ),
  );
}
*/