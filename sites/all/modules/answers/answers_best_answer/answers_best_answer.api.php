<?php
/**
 * @file
 * answers_best_answer hooks.
 */

/**
 * Lets modules know when a best answer is set.
 *
 * @param object $question
 *   The question for which best answer has been set.
 * @param object $answer
 *   The answer which has been marked as the best answer.
 * @param object $old_answer
 *   The previous best answer for the question.
 */
function hook_answers_best_answer_set($question, $answer, $old_answer = NULL) {
  dpm("Best answer set:");
  dpm($answer);
  if ($old_answer) {
    dpm("Old best answer unset:");
    dpm($old_answer);
  }
  else {
    dpm("No old best answer to unset");
  }
}

/**
 * Lets modules know when a best answer is removed.
 *
 * @param object $question
 *   The question for which best answer has been set.
 * @param object $old_answer
 *   The previous best answer for the question.
 */
function hook_answers_best_answer_unset($question, $old_answer) {
  dpm("Best answer unset:");
  dpm($old_answer);
}
