// lib/supabaseClient.js

import { createClient } from '@supabase/supabase-js';

const supabaseUrl = process.env.NEXT_PUBLIC_SUPABASE_URL;  // Ensure the variable is set
const supabaseAnonKey = process.env.NEXT_PUBLIC_SUPABASE_ANON_KEY;  // Ensure this is also set

if (!supabaseUrl || !supabaseAnonKey) {
  throw new Error('Supabase URL and Anon Key are required');
}

export const supabase = createClient(supabaseUrl, supabaseAnonKey);
