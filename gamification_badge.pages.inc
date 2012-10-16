<?php

/**
 * Creating the page(s) content.
 */

function gamification_badge_page() {
  global $user;
  
  if (og_is_member('1')) {
  
  achievements_unlocked_already('quest-1', $user->uid) ? 
    $quest1_status = 'quest-achieved': $quest1_status = 'quest-unachieved';
  achievements_unlocked_already('quest-2', $user->uid) ? 
    $quest2_status = 'quest-achieved': $quest2_status = 'quest-unachieved';
  achievements_unlocked_already('quest-3', $user->uid) ? 
    $quest3_status = 'quest-achieved': $quest3_status = 'quest-unachieved';
  achievements_unlocked_already('badge', $user->uid) ? 
    $questfinal_status = 'quest-achieved': $questfinal_status = 'quest-unachieved';
    
  if (achievements_unlocked_already('quest-1', $user->uid) &&
      achievements_unlocked_already('quest-2', $user->uid) &&
      achievements_unlocked_already('quest-3', $user->uid)) {
        $final_quest_status_message = '<ul class = "quest-list">
        <li class = "' . $questfinal_status .'">' .
          l('Apply what you have learned so far to answer the question and earn your badge.', 'badge/gamification/quest-final') . '</li></ul>';
  }
  else {
    $final_quest_status_message = '<p>When you complete all three quests, you will take a final step to earn your badge.</p>';
  }
  
  $output =  array(
    'introduction' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('In order to earn this badge you will need to be
        able to answer the question: &ldquo;How can I use gamification to
        engage stakeholders in my organization?&rdquo; To develop the knowledge
        needed to answer this question, you will participate in three learning
        quests. Each quest will take approximately 10 minutes to complete.
        They each contain an instructional video, a quizette, and a challenge.
        When you have achieved all 3 quests, you will have the opportunity to
        answer the question and earn your badge.') . '</p>',
    ),
    'quest_list' => array(
      '#type' => 'markup',
      '#markup' => '<ul class = "quest-list">
        <li class = "' . $quest1_status .'">' .
          l('QUEST 1: Games are everywhere', 'badge/gamification/quest-1') . '</li>
        <li class = "' . $quest2_status .'">' .
          l('QUEST 2: Gamification defined', 'badge/gamification/quest-2') . '</li>
        <li class = "' . $quest3_status .'">' .
          l('QUEST 3: Games in practice', 'badge/gamification/quest-3') . '</li>
        </ul>',
    ),
    'final_quest' => array (
      '#type' => 'markup',
      '#markup' => $final_quest_status_message,
      ),
/* This aint working
 * 'quest_list' => array(
      '#items' => array(
        l('QUEST 1: Games are everywhere', 'badge/gamification/quest-1'),
        l('QUEST 2: Gamification defined', 'badge/gamification/quest-2'),
        l('QUEST 3: Games in practice', 'badge/gamification/quest-3'),
      ),
      '#attributes' => array(
        'class' => 'quest-list',
        ),
      '#theme' => 'item_list',
    ),
*/

/* TODO    
    'quest_list' => array(
      '#items' => array(
        'QUEST 1: Games are everywhere',
        'QUEST 2: Gamification defined',
        'QUEST 3: Games in practice',
      ),
      '#theme' => 'item_list',
    ),
      */
  );
    
  }
  else {
    $output =  array(
    'introduction' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('In order to start this badge, you need to join the
        Gamification Badge Participants Group. There you will find other group
        members who are participating in, or have completed the Gamification Badge.') . '</p>
        <p>' . t('After you have joined the group, come back here to start your badge!') . '</p>'
      ),
    'group_button' => array(
      '#type' => 'markup',
      '#markup' => '<div class="group-button">' . l(t('Go to the Gamification
        Badge Group >>'), 'groups/gamification-badge-participants') . '</div>'
      ),
    );
  }
  return $output;
}



function gamification_badge_quest1_page() {
  global $user;
  
  $build = array(
    'subhead' => array(
      '#type' => 'markup',
      '#markup' => '<h2 class="quest-subtitle">' . t('Games are Everywhere') . '</h2>',
    ),

    //display message if quest is already unlocked
    'display_message' => array (
      '#type' => 'markup',
      '#markup' => achievements_unlocked_already('quest-1', $user->uid) ?
        '<div class ="messages warning">' . t('You have already completed this quest.
          You may visit the quest again, but your answers will not count toward the
          badge') . '</div>':NULL,
    ),
    'header_text' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Watch this video and complete the quizette
        below.') . '</p>',
    ),
    'embedded_video' => array(
      '#type' => 'markup',
      '#markup' =>'<iframe width="560" height="315"
        src="http://www.youtube.com/embed/1AJpKt6UP08?rel=0"
        frameborder="0" allowfullscreen></iframe>'
    ),  
    'display_form' => array (
      drupal_get_form('gamification_badge_quest1_form'),
      'file' => 'gamification_badge.forms.inc',    
    ),
    'link_back' => array(
      '#type' => 'markup',
      '#markup' => l('Return to the badge page without answering the
        questions.', '../badge/gamification'),
    ),
  );
     return $build;
}

function gamification_badge_quest2_page() {
  global $user;

   $build = array(
    'subhead' => array(
      '#type' => 'markup',
      '#markup' => '<h2 class="quest-subtitle">' . t('Gamification Defined') . '</h2>',
    ),
    //display message if quest is already unlocked
    'display_message' => array (
      '#type' => 'markup',
      '#markup' => achievements_unlocked_already('quest-2', $user->uid) ?
        '<div class ="messages warning">' . t('You have already completed this quest.
          You may visit the quest again, but your answers will not count toward the
          badge') . '</div>':NULL,
    ),
    'header_text' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Watch this video and complete the quizette
        below.') . '</p>',
    ),
    'embedded_video' => array(
      '#type' => 'markup',
      '#markup' =>'<iframe width="640" height="360"
        src="http://www.youtube.com/embed/1dLK9MW-9sY?rel=0"
        frameborder="0" allowfullscreen></iframe>'
    ), 
    'display_form' => drupal_get_form('gamification_badge_quest2_form'),
    'link_back' => array(
      '#type' => 'markup',
      '#markup' => l('Return to the badge page without answering the
        questions.', '../badge/gamification'),
    ),
  );
     return $build;
}

function gamification_badge_quest3_page() {
  
  module_load_include('inc', 'node', 'node.pages');
  
  global $user;
  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => 'resource',
    'language' => LANGUAGE_NONE,
  );
 
  $build = array(
    'subhead' => array(
      '#type' => 'markup',
      '#markup' => '<h2 class="quest-subtitle">' . t('Games in practice') . '</h2>',
    ),
    //display message if quest is already unlocked
    'display_message' => array (
      '#type' => 'markup',
      '#markup' => achievements_unlocked_already('quest-3', $user->uid) ?
        '<div class ="messages warning">' . t('You have already completed this quest.
          You may visit the quest again, but your answers will not count toward the
          badge') . '</div>':NULL,
    ),
    'header_text' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Watch this video and complete the quizette 
        below.') . '</p>',
    ),
    'embedded_video' => array(
      '#type' => 'markup',
      '#markup' =>'<iframe width="640" height="360"
        src="http://www.youtube.com/embed/nIP4WLROQ50?rel=0"
        frameborder="0" allowfullscreen></iframe>'
    ), 
    'display_form' => drupal_get_form('resource_node_form', $node),
  );

  return $build;
}

function gamification_badge_questfinal_page() {
  
  module_load_include('inc', 'node', 'node.pages');
  
  global $user;
  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => 'discussion_topic',
    'language' => LANGUAGE_NONE,
  );
 
  $build = array(
    //display message if quest is already unlocked
    'display_message' => array (
      '#type' => 'markup',
      '#markup' => achievements_unlocked_already('badge', $user->uid) ?
        '<div class ="messages warning">' . t('You have already completed this quest.
          You may visit the quest again, but your answers will not count toward the
          badge') . '</div>':NULL,
    ),
    'header_text' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('To answer the question, "How can I use
        gamification to engage people in my organization?" and thus earn
        your badge, think of at least 1 example of how you might use an
        aspect of gamification to engage the stakeholders in your
        organization. Write a short paragraph as a response and upload it
        below. Your response will be added to the Gamification Badge
        Participant Group Discussion Board') . '</p>',
    ),
    'display_form' => drupal_get_form('discussion_topic_node_form', $node),
  );
  return $build;
}
