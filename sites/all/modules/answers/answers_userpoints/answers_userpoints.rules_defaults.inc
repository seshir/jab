<?php
/**
 * @file
 * Default rules for the answers_userpoints module.
 */

/**
 * Provide default rules.
 */
function answers_userpoints_default_rules_configuration() {
  $rules['rules_voteup_question'] = entity_import('rules_config', '{ "rules_voteup_question" : {
    "LABEL" : "voteup_question",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "answers" ],
    "REQUIRES" : [ "userpoints_rules", "voting_rules" ],
    "ON" : [ "voting_rules_insert_node" ],
    "DO" : [
      { "userpoints_action_grant_points" : {
          "user" : [ "node:author" ],
          "points" : "10",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "addPoints",
          "display" : 1,
          "moderate" : "default"
      }}
    ]
  }}');

  $rules['rules_votedown_question'] = entity_import('rules_config', '{ "rules_votedown_question" : {
    "LABEL" : "votedown_question",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "answers" ],
    "REQUIRES" : [ "voting_rules", "userpoints_rules" ],
    "ON" : [ "voting_rules_insert_node" ],
    "IF" : [
      { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "-1" } }
    ],
    "DO" : [
      { "userpoints_action_grant_points" : {
          "user" : [ "node:author" ],
          "points" : "-2",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "removePoints",
          "display" : 1,
          "moderate" : "default"
        }
      },
      { "userpoints_action_grant_points" : {
          "user" : [ "vote:user" ],
          "points" : "-1",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "removePoints",
          "display" : 1,
          "moderate" : "default"
      }}
    ]
  }}');

  $rules['rules_flag_answers_best_answer'] = entity_import('rules_config', '{ "rules_flag_answers_best_answer" : {
    "LABEL" : "flag_answers_best_answer",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "answers" ],
    "REQUIRES" : [ "userpoints_rules", "flag" ],
    "ON" : [ "flag_flagged_best_answer" ],
    "IF" : [
      { "NOT data_is" : { "data" : [ "flagging-user" ], "value" : [ "flagged-node:author" ] } }
    ],
    "DO" : [
      { "userpoints_action_grant_points" : {
          "user" : [ "flagged-node:author" ],
          "points" : "15",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "addPoints",
          "display" : 1,
          "moderate" : "default"
        }
      },
      { "userpoints_action_grant_points" : {
          "user" : [ "flagging-user" ],
          "points" : "2",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "addPoints",
          "display" : 1,
          "moderate" : "default"
      }}
    ]
  }}');

  $rules['rules_unflag_answers_best_answer'] = entity_import('rules_config', '{ "rules_unflag_answers_best_answer" : {
    "LABEL" : "unflag_answers_best_answer",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "answers" ],
    "REQUIRES" : [ "userpoints_rules", "flag" ],
    "ON" : [ "flag_unflagged_best_answer" ],
    "IF" : [
      { "NOT data_is" : { "data" : [ "flagging-user" ], "value" : [ "flagged-node:author" ] } }
    ],
    "DO" : [
      { "userpoints_action_grant_points" : {
          "user" : [ "flagged-node:author" ],
          "points" : "-15",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "addPoints",
          "display" : 1,
          "moderate" : "default"
        }
      },
      { "userpoints_action_grant_points" : {
          "user" : [ "flagging-user" ],
          "points" : "-2",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "removePoints",
          "display" : 1,
          "moderate" : "default"
      }}
    ]
  }}');

  return $rules;
}
