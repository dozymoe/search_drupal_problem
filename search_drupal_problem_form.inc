<?php
/**
 * @file
 * Codes to display a form.
 */

/**
 * Produce the content of path /search-drupal-problem.
 */
function search_drupal_problem_form_view(array $form, array &$form_state) {
  drupal_set_title('Search Drupal problem');
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Search text'),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['text']) ? $form_state['values']['text'] : '',
  );
  $form['project'] = array(
    '#type' => 'textfield',
    '#title' => t('Drupal project'),
    '#default_value' => !empty($form_state['values']['project']) ? $form_state['values']['project'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
  );
  $output = '<div><output name=result>';
  $output .= !empty($form_state['values']['result']) ? $form_state['values']['result'] : '';
  $output .= '</output></div>';
  $form['output'] = array(
    '#markup' => $output,
  );

  return $form;
}

/**
 * Validate function for search_drupal_problem_form_view().
 */
function search_drupal_problem_form_view_validate(array $form, array &$form_state) {
}

/**
 * Submit function for search_drupal_problem_form_view().
 */
function search_drupal_problem_form_view_submit(array $form, array &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['values']['result'] = _search_drupal_problem_execute($form_state['values']['text'], $form_state['values']['project']);
}
