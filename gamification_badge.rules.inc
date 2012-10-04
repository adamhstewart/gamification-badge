<?php

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